
#include "flextVk.h"

VkResult(VKAPI_PTR *flextvkAcquireNextImageKHR)(VkDevice, VkSwapchainKHR, uint64_t, VkSemaphore, VkFence, uint32_t*) = nullptr;
VkResult(VKAPI_PTR *flextvkCreateBuffer)(VkDevice, const VkBufferCreateInfo*, const VkAllocationCallbacks*, VkBuffer*) = nullptr;
PFN_vkVoidFunction(VKAPI_PTR *flextvkGetDeviceProcAddr)(VkDevice, const char*) = nullptr;

void flextVkInit(VkInstance instance) {
    flextvkAcquireNextImageKHR = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkSwapchainKHR, uint64_t, VkSemaphore, VkFence, uint32_t*)>(vkGetInstanceProcAddr(instance, "vkAcquireNextImageKHR"));
    flextvkCreateBuffer = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkBufferCreateInfo*, const VkAllocationCallbacks*, VkBuffer*)>(vkGetInstanceProcAddr(instance, "vkCreateBuffer"));
    flextvkGetDeviceProcAddr = reinterpret_cast<PFN_vkVoidFunction(VKAPI_PTR*)(VkDevice, const char*)>(vkGetInstanceProcAddr(instance, "vkGetDeviceProcAddr"));
}
