/*
    This file was generated using https://github.com/mosra/flextgl:

        path/to/flextGLgen.py -D generated -t somepath profile-vk.txt

    Do not edit directly, modify the template or profile and regenerate.
*/

#include "flextVk.h"

VkResult(VKAPI_PTR *flextvkAcquireNextImageKHR)(VkDevice, VkSwapchainKHR, uint64_t, VkSemaphore, VkFence, uint32_t*) = nullptr;
VkResult(VKAPI_PTR *flextvkCreateBuffer)(VkDevice, const VkBufferCreateInfo*, const VkAllocationCallbacks*, VkBuffer*) = nullptr;
PFN_vkVoidFunction(VKAPI_PTR *flextvkGetDeviceProcAddr)(VkDevice, const char*) = nullptr;
VkResult(VKAPI_PTR *flextvkEnumerateInstanceVersion)(uint32_t*) = nullptr;

void flextVkInit() {
    /* All functions that are present already in 1.0 are loaded statically, but
       the following are not, so we have to load them at runtime */
    flextvkEnumerateInstanceVersion = reinterpret_cast<VkResult(VKAPI_PTR*)(uint32_t*)>(vkGetInstanceProcAddr(nullptr, "vkEnumerateInstanceVersion"));
}

void flextVkInitInstance(VkInstance instance) {
    flextvkAcquireNextImageKHR = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkSwapchainKHR, uint64_t, VkSemaphore, VkFence, uint32_t*)>(vkGetInstanceProcAddr(instance, "vkAcquireNextImageKHR"));
    flextvkCreateBuffer = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkBufferCreateInfo*, const VkAllocationCallbacks*, VkBuffer*)>(vkGetInstanceProcAddr(instance, "vkCreateBuffer"));
    flextvkGetDeviceProcAddr = reinterpret_cast<PFN_vkVoidFunction(VKAPI_PTR*)(VkDevice, const char*)>(vkGetInstanceProcAddr(instance, "vkGetDeviceProcAddr"));
}
