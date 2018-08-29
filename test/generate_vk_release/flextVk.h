/* A minimal template to test all corner cases. Not to be used directly. */

#include <stdint.h>
#include <stddef.h>

#define VKAPI_PTR

/* Vulkan 1.1 */

/* Enums */

/* VK_VERSION_1_0 */

#define VK_LOD_CLAMP_NONE 1000.0f
#define VK_REMAINING_MIP_LEVELS (~0U)
#define VK_REMAINING_ARRAY_LAYERS (~0U)
#define VK_WHOLE_SIZE (~0ULL)
#define VK_ATTACHMENT_UNUSED (~0U)
#define VK_TRUE 1
#define VK_FALSE 0
#define VK_QUEUE_FAMILY_IGNORED (~0U)
#define VK_SUBPASS_EXTERNAL (~0U)

/* VK_VERSION_1_1 */

#define VK_MAX_DEVICE_GROUP_SIZE 32
#define VK_LUID_SIZE 8
#define VK_QUEUE_FAMILY_EXTERNAL (~0U-1)

/* Data types */

#define VK_MAKE_VERSION(major, minor, patch) \
    (((major) << 22) | ((minor) << 12) | (patch))
#define VK_VERSION_MAJOR(version) ((uint32_t)(version) >> 22)
#define VK_VERSION_MINOR(version) (((uint32_t)(version) >> 12) & 0x3ff)
#define VK_VERSION_PATCH(version) ((uint32_t)(version) & 0xfff)
// Vulkan 1.0 version number
#define VK_API_VERSION_1_0 VK_MAKE_VERSION(1, 0, 0)// Patch version should always be set to 0
// Vulkan 1.1 version number
#define VK_API_VERSION_1_1 VK_MAKE_VERSION(1, 1, 0)// Patch version should always be set to 0
// Version of this file
#define VK_HEADER_VERSION 73
#define VK_DEFINE_HANDLE(object) typedef struct object##_T* object;
#define VK_NULL_HANDLE 0
VK_DEFINE_HANDLE(VkInstance)
VK_DEFINE_HANDLE(VkDevice)
VK_DEFINE_HANDLE(VkCommandBuffer)

typedef enum {
    VK_PIPELINE_CACHE_HEADER_VERSION_ONE = 1
} VkPipelineCacheHeaderVersion;
typedef void (VKAPI_PTR *PFN_vkVoidFunction)(void);

typedef struct VkDrawIndirectCommand {
    uint32_t               vertexCount;
    uint32_t               instanceCount;
    uint32_t               firstVertex;
    uint32_t               firstInstance;
} VkDrawIndirectCommand;

typedef struct VkDrawIndexedIndirectCommand {
    uint32_t               indexCount;
    uint32_t               instanceCount;
    uint32_t               firstIndex;
    int32_t                vertexOffset;
    uint32_t               firstInstance;
} VkDrawIndexedIndirectCommand;

typedef struct VkDispatchIndirectCommand {
    uint32_t               x;
    uint32_t               y;
    uint32_t               z;
} VkDispatchIndirectCommand;

PFN_vkVoidFunction vkGetInstanceProcAddr(VkInstance, const char*);

/* Global function pointers */

/* Global function pointer initialization */
void flextVkInit();

/* Per-instance function pointers */
struct FlextVkInstance {
    PFN_vkVoidFunction    (*GetDeviceProcAddr)(VkDevice, const char*);
};

/* Per-instance function pointer initialization */
void flextVkInitInstance(VkInstance instance, FlextVkInstance* data);

/* Per-device function pointers */
struct FlextVkDevice {
    void    (*CmdDraw)(VkCommandBuffer, uint32_t, uint32_t, uint32_t, uint32_t);
    void    (*CmdDrawIndexed)(VkCommandBuffer, uint32_t, uint32_t, uint32_t, int32_t, uint32_t);
};

void flextVkInit() {
}

void flextVkInitInstance(VkInstance instance, FlextVkInstance* data) {
    data->GetDeviceProcAddr = reinterpret_cast<PFN_vkVoidFunction(*)(VkDevice, const char*)>(vkGetInstanceProcAddr(instance, "vkGetDeviceProcAddr"));
}

void flextVkInitDevice(VkDevice device, FlextVkDevice* data, PFN_vkVoidFunction( *getDeviceProcAddr)(VkDevice, const char*)) {
    data->CmdDraw = reinterpret_cast<void(*)(VkCommandBuffer, uint32_t, uint32_t, uint32_t, uint32_t)>(getDeviceProcAddr(device, "vkCmdDraw"));
    data->CmdDrawIndexed = reinterpret_cast<void(*)(VkCommandBuffer, uint32_t, uint32_t, uint32_t, int32_t, uint32_t)>(getDeviceProcAddr(device, "vkCmdDrawIndexed"));
}
