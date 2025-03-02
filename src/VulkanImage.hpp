#pragma once

#include <cstdint>
#include <vulkan/vulkan.h>

#include <filesystem>
#include <vulkan/vulkan_core.h>

class VulkanImage {
public:
  VulkanImage(VkDevice &device, VkPhysicalDevice &physicalDevice,
              VkQueue &graphicsQueue);
  ~VulkanImage();

  bool createDefault(VkCommandPool cmdPool);
  bool createFromFile(std::filesystem::path path, VkCommandPool cmdPool);

  VkSampler sampler{};
  VkImageView imageView{};

protected:
  void transitionImageLayout(VkCommandPool cmdPool, VkImageLayout oldLayout,
                             VkImageLayout newLayout);
  void cleanupImageResources();
  bool createFromData(uint32_t width, uint32_t height, uint8_t *data,
                      VkCommandPool cmdPool);

  VkDevice &device;
  VkPhysicalDevice &physicalDevice;
  VkQueue &graphicsQueue;

  VkImage textureImage{};
  VkDeviceMemory textureImageMemory{};
};
