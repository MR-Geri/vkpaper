#include <VulkanImage.hpp>

#include <VulkanUtils.hpp>

#include <cstdint>
#include <pthread.h>
#include <vulkan/vulkan_core.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <array>
#include <iostream>

constexpr auto IMAGE_FORMAT = VK_FORMAT_R8G8B8A8_SRGB;

VulkanImage::VulkanImage(VkDevice &device_, VkPhysicalDevice &physicalDevice_,
                         VkQueue &graphicsQueue_)
    : device{device_}, physicalDevice(physicalDevice_),
      graphicsQueue{graphicsQueue_}, textureImage{VK_NULL_HANDLE},
      textureImageMemory{VK_NULL_HANDLE}, imageView{VK_NULL_HANDLE},
      sampler{VK_NULL_HANDLE} {
  VkSamplerCreateInfo samplerInfo{};
  samplerInfo.sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
  samplerInfo.magFilter = VK_FILTER_LINEAR;
  samplerInfo.minFilter = VK_FILTER_LINEAR;

  if (vkCreateSampler(device, &samplerInfo, nullptr, &sampler) != VK_SUCCESS) {
    throw std::runtime_error("failed to create texture sampler!");
  }
}

VulkanImage::~VulkanImage() {
  cleanupImageResources();

  if (sampler != VK_NULL_HANDLE) {
    vkDestroySampler(device, sampler, nullptr);
  }
}

void VulkanImage::cleanupImageResources() {
  if (textureImage != VK_NULL_HANDLE) {
    vkDestroyImage(device, textureImage, nullptr);
  }

  if (textureImageMemory != VK_NULL_HANDLE) {
    vkFreeMemory(device, textureImageMemory, nullptr);
  }

  if (imageView != VK_NULL_HANDLE) {
    vkDestroyImageView(device, imageView, nullptr);
  }
}

bool VulkanImage::createDefault(VkCommandPool cmdPool) {
  auto pixel = std::array<float, 4>{0.0f, 0.0f, 0.0f, 1.0f};
  return createFromData(1, 1, reinterpret_cast<uint8_t *>(pixel.data()),
                        cmdPool);
}

bool VulkanImage::createFromFile(std::filesystem::path path,
                                 VkCommandPool cmdPool) {
  std::cout << "Loading image from " << path << "...\n";

  int texWidth, texHeight, texChannels;
  stbi_set_flip_vertically_on_load(true);
  auto pixels = stbi_load(path.c_str(), &texWidth, &texHeight, &texChannels,
                          STBI_rgb_alpha);

  if (!pixels) {
    std::cerr << "Could not load image " << path << " with stb!\n";
    return false;
  }

  auto result = createFromData(texWidth, texHeight, pixels, cmdPool);

  stbi_image_free(pixels);

  return result;
}

bool VulkanImage::createFromData(uint32_t width, uint32_t height,
                                 uint8_t *texData, VkCommandPool cmdPool) {
  cleanupImageResources();

  VkDeviceSize imageSize = width * height * 4;

  VkBuffer stagingBuffer;
  VkDeviceMemory stagingBufferMemory;

  createBuffer(device, physicalDevice, imageSize,
               VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
               VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
                   VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
               stagingBuffer, stagingBufferMemory);

  void *mappedData;
  vkMapMemory(device, stagingBufferMemory, 0, imageSize, 0, &mappedData);
  memcpy(mappedData, texData, static_cast<size_t>(imageSize));
  vkUnmapMemory(device, stagingBufferMemory);

  VkImageCreateInfo imageInfo{};
  imageInfo.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
  imageInfo.imageType = VK_IMAGE_TYPE_2D;
  imageInfo.extent.width = width;
  imageInfo.extent.height = height;
  imageInfo.extent.depth = 1;
  imageInfo.mipLevels = 1;
  imageInfo.arrayLayers = 1;
  imageInfo.format = IMAGE_FORMAT;
  imageInfo.tiling = VK_IMAGE_TILING_OPTIMAL;
  imageInfo.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
  imageInfo.usage =
      VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT;
  imageInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
  imageInfo.samples = VK_SAMPLE_COUNT_1_BIT;

  if (vkCreateImage(device, &imageInfo, nullptr, &textureImage) != VK_SUCCESS) {
    std::cerr << "Could not create VkImage during image creation!\n";
    return false;
  }

  VkMemoryRequirements memRequirements;
  vkGetImageMemoryRequirements(device, textureImage, &memRequirements);

  VkMemoryAllocateInfo allocInfo{};
  allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
  allocInfo.allocationSize = memRequirements.size;
  allocInfo.memoryTypeIndex =
      findMemoryType(physicalDevice, memRequirements.memoryTypeBits,
                     VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);

  if (vkAllocateMemory(device, &allocInfo, nullptr, &textureImageMemory) !=
      VK_SUCCESS) {
    std::cerr << "Could not allocate memory for image creation!\n";
    return false;
  }

  vkBindImageMemory(device, textureImage, textureImageMemory, 0);

  transitionImageLayout(cmdPool, VK_IMAGE_LAYOUT_UNDEFINED,
                        VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL);
  copyBufferToImage(device, graphicsQueue, cmdPool, stagingBuffer, textureImage,
                    static_cast<uint32_t>(width),
                    static_cast<uint32_t>(height));
  transitionImageLayout(cmdPool, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                        VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);

  vkDestroyBuffer(device, stagingBuffer, nullptr);
  vkFreeMemory(device, stagingBufferMemory, nullptr);

  VkImageViewCreateInfo viewInfo{};
  viewInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
  viewInfo.image = textureImage;
  viewInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
  viewInfo.format = VK_FORMAT_R8G8B8A8_SRGB;
  viewInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
  viewInfo.subresourceRange.baseMipLevel = 0;
  viewInfo.subresourceRange.levelCount = 1;
  viewInfo.subresourceRange.baseArrayLayer = 0;
  viewInfo.subresourceRange.layerCount = 1;
  if (vkCreateImageView(device, &viewInfo, nullptr, &imageView) != VK_SUCCESS) {
    std::cerr << "Could not create image view!\n";
    return false;
  }

  return true;
}

void VulkanImage::transitionImageLayout(VkCommandPool commandPool,
                                        VkImageLayout oldLayout,
                                        VkImageLayout newLayout) {
  VkCommandBuffer commandBuffer = beginSingleTimeCommands(device, commandPool);

  VkImageMemoryBarrier barrier{};
  barrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
  barrier.oldLayout = oldLayout;
  barrier.newLayout = newLayout;
  barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
  barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
  barrier.image = textureImage;
  barrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
  barrier.subresourceRange.baseMipLevel = 0;
  barrier.subresourceRange.levelCount = 1;
  barrier.subresourceRange.baseArrayLayer = 0;
  barrier.subresourceRange.layerCount = 1;

  VkPipelineStageFlags sourceStage;
  VkPipelineStageFlags destinationStage;

  if (oldLayout == VK_IMAGE_LAYOUT_UNDEFINED &&
      newLayout == VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL) {
    barrier.srcAccessMask = 0;
    barrier.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;

    sourceStage = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;
    destinationStage = VK_PIPELINE_STAGE_TRANSFER_BIT;
  } else if (oldLayout == VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL &&
             newLayout == VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL) {
    barrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
    barrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;

    sourceStage = VK_PIPELINE_STAGE_TRANSFER_BIT;
    destinationStage = VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT;
  } else {
    throw std::invalid_argument("unsupported layout transition!");
  }

  vkCmdPipelineBarrier(commandBuffer, sourceStage, destinationStage, 0, 0,
                       nullptr, 0, nullptr, 1, &barrier);

  endSingleTimeCommands(device, graphicsQueue, commandPool, commandBuffer);
}
