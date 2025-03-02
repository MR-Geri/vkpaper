#pragma once

#include <vulkan/vulkan.h>

uint32_t findMemoryType(VkPhysicalDevice physicalDevice, uint32_t typeFilter,
                        VkMemoryPropertyFlags properties);
VkCommandBuffer beginSingleTimeCommands(VkDevice device, VkCommandPool cmdPool);
void endSingleTimeCommands(VkDevice device, VkQueue graphicsQueue,
                           VkCommandPool cmdPool,
                           VkCommandBuffer commandBuffer);

void createBuffer(VkDevice device, VkPhysicalDevice pyhsicalDevice,
                  VkDeviceSize size, VkBufferUsageFlags usage,
                  VkMemoryPropertyFlags properties, VkBuffer &buffer,
                  VkDeviceMemory &bufferMemory);

void copyBufferToImage(VkDevice device, VkQueue graphicsQueue,
                       VkCommandPool cmdPool, VkBuffer buffer, VkImage image,
                       uint32_t width, uint32_t height);
