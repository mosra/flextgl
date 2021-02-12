/*
    This file was generated using https://github.com/mosra/flextgl:

        path/to/flextGLgen.py -D generated -t somepath profile-vk.txt

    Do not edit directly, modify the template or profile and regenerate.
*/

#include "flextVk.h"

/* The following definitions and flextDynamicLoader are borrowed/modified from vulkan.hpp DynamicLoader */
// Copyright (c) 2015-2020 The Khronos Group Inc.
//
// SPDX-License-Identifier: Apache-2.0 OR MIT
//
#if defined(__linux__) || defined(__APPLE__)
    #include <dlfcn.h>
#elif defined(_WIN32)
    typedef struct HINSTANCE__ *HINSTANCE;
    #if defined(_WIN64)
        typedef int64_t(__stdcall *FARPROC)();
    #else
        typedef int(__stdcall *FARPROC)();
    #endif
    extern "C" __declspec(dllimport) HINSTANCE __stdcall LoadLibraryA(char const *lpLibFileName);
    extern "C" __declspec(dllimport) int __stdcall FreeLibrary(HINSTANCE hLibModule);
    extern "C" __declspec(dllimport) FARPROC __stdcall GetProcAddress(HINSTANCE hModule, const char *lpProcName);
#endif

class flextDynamicLoader {
public:
    flextDynamicLoader() : m_success(false), m_library(nullptr) {
    }
    ~flextDynamicLoader() {
        if (m_library) {
#if defined(__linux__) || defined(__APPLE__)
            dlclose(m_library);
#elif defined(_WIN32)
            ::FreeLibrary(m_library);
#else
#error unsupported platform
#endif
        }
    }

    bool init() {
        if (m_success) return true;
#if defined(__linux__)
        m_library = dlopen("libvulkan.so", RTLD_NOW | RTLD_LOCAL);
        if (m_library == nullptr) {
            m_library = dlopen("libvulkan.so.1", RTLD_NOW | RTLD_LOCAL);
        }
        m_success = (m_library != nullptr);
#elif defined(__APPLE__)
        m_library = dlopen("libvulkan.dylib", RTLD_NOW | RTLD_LOCAL);
        m_success = (m_library != nullptr);
#elif defined(_WIN32)
        m_library = ::LoadLibraryA("vulkan-1.dll");
        m_success = (m_library != nullptr);
#else
#error unsupported platform
#endif
        return m_success;
    }

#if defined(__linux__) || defined(__APPLE__)
    void*
#elif defined(_WIN32)
    FARPROC
#else
#error unsupported platform
#endif
    getProcAddress(const char *function) const {
#if defined(__linux__) || defined(__APPLE__)
        return dlsym(m_library, function);
#elif defined(_WIN32)
        return ::GetProcAddress(m_library, function);
#else
#error unsupported platform
#endif
    }

private:
    bool m_success;
#if defined(__linux__) || defined(__APPLE__)
    void *m_library;
#elif defined(_WIN32)
    ::HINSTANCE m_library;
#else
#error unsupported platform
#endif
};

VkResult(VKAPI_PTR *flextvkAcquireNextImageKHR)(VkDevice, VkSwapchainKHR, uint64_t, VkSemaphore, VkFence, uint32_t*) = nullptr;
VkResult(VKAPI_PTR *flextvkCreateBuffer)(VkDevice, const VkBufferCreateInfo*, const VkAllocationCallbacks*, VkBuffer*) = nullptr;
PFN_vkVoidFunction(VKAPI_PTR *flextvkGetDeviceProcAddr)(VkDevice, const char*) = nullptr;
PFN_vkVoidFunction(VKAPI_PTR *flextvkGetInstanceProcAddr)(VkInstance, const char*) = nullptr;
VkResult(VKAPI_PTR *flextvkEnumerateInstanceVersion)(uint32_t*) = nullptr;

bool flextVkInit() {
    static flextDynamicLoader loader;
    if (!loader.init()) return false;
    flextvkGetInstanceProcAddr = reinterpret_cast<PFN_vkVoidFunction(VKAPI_PTR*)(VkInstance, const char*)>(loader.getProcAddress("vkGetInstanceProcAddr"));
    if (flextvkGetInstanceProcAddr) {
        flextvkEnumerateInstanceVersion = reinterpret_cast<VkResult(VKAPI_PTR*)(uint32_t*)>(flextvkGetInstanceProcAddr(nullptr, "vkEnumerateInstanceVersion"));
    }
    return true;
}

void flextVkInitInstance(VkInstance instance) {
    flextvkAcquireNextImageKHR = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, VkSwapchainKHR, uint64_t, VkSemaphore, VkFence, uint32_t*)>(flextvkGetInstanceProcAddr(instance, "vkAcquireNextImageKHR"));
    flextvkCreateBuffer = reinterpret_cast<VkResult(VKAPI_PTR*)(VkDevice, const VkBufferCreateInfo*, const VkAllocationCallbacks*, VkBuffer*)>(flextvkGetInstanceProcAddr(instance, "vkCreateBuffer"));
    flextvkGetDeviceProcAddr = reinterpret_cast<PFN_vkVoidFunction(VKAPI_PTR*)(VkDevice, const char*)>(flextvkGetInstanceProcAddr(instance, "vkGetDeviceProcAddr"));
}
