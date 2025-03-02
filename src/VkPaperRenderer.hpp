#pragma once

#include <VulkanImage.hpp>

#include <memory>
#include <vulkan/vulkan.h>
#include <vulkan/vulkan_wayland.h>

#include <array>
#include <optional>
#include <vector>

const int MAX_SAMPLER = 4;

struct Vec3 {
  float x;
  float y;
  float z;
  float _unused; // account for the fact that vec3 has equal size to vec4 in
                 // std140 layouts
};

struct Vec4 {
  float x;
  float y;
  float z;
  float w;
};

struct UniformBuffer {
  float iTime;
  float iTimeDelta;
  float iFrameRate;
  int iFrame;

  Vec4 iMouse;
  Vec3 iResolution;

  Vec3 iChannelResolution[4];
  float iChannelTime[4];
};

struct SwapChainSupportDetails {
  VkSurfaceCapabilitiesKHR capabilities;
  std::vector<VkSurfaceFormatKHR> formats;
  std::vector<VkPresentModeKHR> presentModes;
};

struct QueueFamilyIndices {
  std::optional<uint32_t> graphicsFamily;
  std::optional<uint32_t> presentFamily;

  bool isComplete() {
    return graphicsFamily.has_value() && presentFamily.has_value();
  }
};

class VkPaperRenderer {
public:
  VkPaperRenderer(wl_display *wl_display_, wl_surface *wl_surface_)
      : wlDisplay(wl_display_), wlSurface(wl_surface_) {
    initVulkan();
  }
  ~VkPaperRenderer() { cleanup(); }

  void drawFrame();
  void updateUniformBuffer(UniformBuffer uniformBuffer);
  void loadImageForSampler(uint32_t samplerId, std::filesystem::path path);

private:
  void initVulkan();
  void cleanupSwapChain();
  void cleanup();
  void recreateSwapChain();
  void createInstance();
  void populateDebugMessengerCreateInfo(
      VkDebugUtilsMessengerCreateInfoEXT &createInfo);
  void setupDebugMessenger();
  void createSurface();
  void pickPhysicalDevice();
  void createLogicalDevice();
  void createSwapChain();
  void createImageViews();
  void createRenderPass();
  void createGraphicsPipeline();
  void createFramebuffers();
  void createCommandPool();
  void createVertexBuffer();
  void createUniformBuffers();
  void createDescriptorPool();
  void createDescriptorSets();
  void createDescriptorSetLayout();
  void createCommandBuffers();
  void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
  void createSyncObjects();

  VkShaderModule createShaderModule(const std::vector<char> &code);
  SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
  bool isDeviceSuitable(VkPhysicalDevice device);
  QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

private:
  VkInstance instance;
  VkDebugUtilsMessengerEXT debugMessenger;
  VkSurfaceKHR surface;

  VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
  VkDevice device;

  VkQueue graphicsQueue;
  VkQueue presentQueue;

  // swapchain
  VkSwapchainKHR swapChain;
  std::vector<VkImage> swapChainImages;
  VkFormat swapChainImageFormat;
  VkExtent2D swapChainExtent;
  std::vector<VkImageView> swapChainImageViews;
  std::vector<VkFramebuffer> swapChainFramebuffers;

  // render passes and pipelines
  VkRenderPass renderPass;
  VkDescriptorSetLayout descriptorSetLayout;
  VkPipelineLayout pipelineLayout;
  VkPipeline graphicsPipeline;

  // uniform buffers
  std::vector<VkBuffer> uniformBuffers;
  std::vector<VkDeviceMemory> uniformBuffersMemory;
  std::vector<void *> uniformBuffersMapped;

  // descripors
  VkDescriptorPool descriptorPool;
  std::vector<VkDescriptorSet> descriptorSets;

  // vertex buffers
  VkBuffer vertexBuffer;
  VkDeviceMemory vertexBufferMemory;

  // command buffers
  VkCommandPool commandPool;
  std::vector<VkCommandBuffer> commandBuffers;

  std::array<std::unique_ptr<VulkanImage>, MAX_SAMPLER> images;

  // synchronization
  std::vector<VkSemaphore> imageAvailableSemaphores;
  std::vector<VkSemaphore> renderFinishedSemaphores;
  std::vector<VkFence> inFlightFences;
  uint32_t currentFrame = 0;

  bool framebufferResized = false;

  wl_display *wlDisplay;
  wl_surface *wlSurface;
};
