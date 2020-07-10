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
#define VK_HEADER_VERSION 124
#define VK_DEFINE_HANDLE(object) typedef struct object##_T* object;
#define VK_NULL_HANDLE 0
typedef uint32_t VkBool32;
typedef uint32_t VkFlags;
typedef VkFlags VkDeviceCreateFlags;
typedef VkFlags VkDeviceQueueCreateFlags;
VK_DEFINE_HANDLE(VkInstance)
VK_DEFINE_HANDLE(VkPhysicalDevice)
VK_DEFINE_HANDLE(VkDevice)

typedef enum {
    VK_PIPELINE_CACHE_HEADER_VERSION_ONE = 1
} VkPipelineCacheHeaderVersion;

typedef enum {
    VK_DEVICE_QUEUE_CREATE_PROTECTED_BIT = 1 << 0
} VkDeviceQueueCreateFlagBits;

typedef enum {
    VK_SUCCESS = 0,
    VK_NOT_READY = 1,
    VK_TIMEOUT = 2,
    VK_EVENT_SET = 3,
    VK_EVENT_RESET = 4,
    VK_INCOMPLETE = 5,
    VK_ERROR_OUT_OF_HOST_MEMORY = -1,
    VK_ERROR_OUT_OF_DEVICE_MEMORY = -2,
    VK_ERROR_INITIALIZATION_FAILED = -3,
    VK_ERROR_DEVICE_LOST = -4,
    VK_ERROR_MEMORY_MAP_FAILED = -5,
    VK_ERROR_LAYER_NOT_PRESENT = -6,
    VK_ERROR_EXTENSION_NOT_PRESENT = -7,
    VK_ERROR_FEATURE_NOT_PRESENT = -8,
    VK_ERROR_INCOMPATIBLE_DRIVER = -9,
    VK_ERROR_TOO_MANY_OBJECTS = -10,
    VK_ERROR_FORMAT_NOT_SUPPORTED = -11,
    VK_ERROR_FRAGMENTED_POOL = -12,
    VK_ERROR_OUT_OF_POOL_MEMORY = -1000069000,
    VK_ERROR_INVALID_EXTERNAL_HANDLE = -1000072003
} VkResult;

typedef enum {
    VK_STRUCTURE_TYPE_APPLICATION_INFO = 0,
    VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO = 1,
    VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO = 2,
    VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO = 3,
    VK_STRUCTURE_TYPE_SUBMIT_INFO = 4,
    VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO = 5,
    VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE = 6,
    VK_STRUCTURE_TYPE_BIND_SPARSE_INFO = 7,
    VK_STRUCTURE_TYPE_FENCE_CREATE_INFO = 8,
    VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO = 9,
    VK_STRUCTURE_TYPE_EVENT_CREATE_INFO = 10,
    VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO = 11,
    VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO = 12,
    VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO = 13,
    VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO = 14,
    VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO = 15,
    VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO = 16,
    VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO = 17,
    VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO = 18,
    VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO = 19,
    VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO = 20,
    VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO = 21,
    VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO = 22,
    VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO = 23,
    VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO = 24,
    VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO = 25,
    VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO = 26,
    VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO = 27,
    VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO = 28,
    VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO = 29,
    VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO = 30,
    VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO = 31,
    VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO = 32,
    VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO = 33,
    VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO = 34,
    VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET = 35,
    VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET = 36,
    VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO = 37,
    VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO = 38,
    VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO = 39,
    VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO = 40,
    VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO = 41,
    VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO = 42,
    VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO = 43,
    VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER = 44,
    VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER = 45,
    VK_STRUCTURE_TYPE_MEMORY_BARRIER = 46,
    VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO = 47,
    VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO = 48,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES = 1000094000,
    VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO = 1000157000,
    VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO = 1000157001,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES = 1000083000,
    VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS = 1000127000,
    VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO = 1000127001,
    VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO = 1000060000,
    VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO = 1000060003,
    VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO = 1000060004,
    VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO = 1000060005,
    VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO = 1000060006,
    VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO = 1000060013,
    VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO = 1000060014,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES = 1000070000,
    VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO = 1000070001,
    VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2 = 1000146000,
    VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2 = 1000146001,
    VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2 = 1000146002,
    VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2 = 1000146003,
    VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2 = 1000146004,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2 = 1000059000,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2 = 1000059001,
    VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2 = 1000059002,
    VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2 = 1000059003,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2 = 1000059004,
    VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2 = 1000059005,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2 = 1000059006,
    VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2 = 1000059007,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2 = 1000059008,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES = 1000117000,
    VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO = 1000117001,
    VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO = 1000117002,
    VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO = 1000117003,
    VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO = 1000053000,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES = 1000053001,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES = 1000053002,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES = 1000120000,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTER_FEATURES = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES,
    VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO = 1000145000,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES = 1000145001,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES = 1000145002,
    VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2 = 1000145003,
    VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO = 1000156000,
    VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO = 1000156001,
    VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO = 1000156002,
    VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO = 1000156003,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES = 1000156004,
    VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES = 1000156005,
    VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO = 1000085000,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO = 1000071000,
    VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES = 1000071001,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO = 1000071002,
    VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES = 1000071003,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES = 1000071004,
    VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO = 1000072000,
    VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO = 1000072001,
    VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO = 1000072002,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO = 1000112000,
    VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES = 1000112001,
    VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO = 1000113000,
    VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO = 1000077000,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO = 1000076000,
    VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES = 1000076001,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES = 1000168000,
    VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT = 1000168001,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES = 1000063000,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETER_FEATURES = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES
} VkStructureType;

typedef enum {
    VK_SYSTEM_ALLOCATION_SCOPE_COMMAND = 0,
    VK_SYSTEM_ALLOCATION_SCOPE_OBJECT = 1,
    VK_SYSTEM_ALLOCATION_SCOPE_CACHE = 2,
    VK_SYSTEM_ALLOCATION_SCOPE_DEVICE = 3,
    VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE = 4
} VkSystemAllocationScope;

typedef enum {
    VK_INTERNAL_ALLOCATION_TYPE_EXECUTABLE = 0
} VkInternalAllocationType;

typedef enum {
    VK_VENDOR_ID_VIV = 0x10001,
    VK_VENDOR_ID_VSI = 0x10002,
    VK_VENDOR_ID_KAZAN = 0x10003
} VkVendorId;
typedef void (VKAPI_PTR *PFN_vkInternalAllocationNotification)(
    void*                                       pUserData,
    size_t                                      size,
    VkInternalAllocationType                    allocationType,
    VkSystemAllocationScope                     allocationScope);
typedef void (VKAPI_PTR *PFN_vkInternalFreeNotification)(
    void*                                       pUserData,
    size_t                                      size,
    VkInternalAllocationType                    allocationType,
    VkSystemAllocationScope                     allocationScope);
typedef void* (VKAPI_PTR *PFN_vkReallocationFunction)(
    void*                                       pUserData,
    void*                                       pOriginal,
    size_t                                      size,
    size_t                                      alignment,
    VkSystemAllocationScope                     allocationScope);
typedef void* (VKAPI_PTR *PFN_vkAllocationFunction)(
    void*                                       pUserData,
    size_t                                      size,
    size_t                                      alignment,
    VkSystemAllocationScope                     allocationScope);
typedef void (VKAPI_PTR *PFN_vkFreeFunction)(
    void*                                       pUserData,
    void*                                       pMemory);
typedef void (VKAPI_PTR *PFN_vkVoidFunction)(void);

typedef struct VkBaseOutStructure {
    VkStructureType sType;
    struct VkBaseOutStructure* pNext;
} VkBaseOutStructure;

typedef struct VkBaseInStructure {
    VkStructureType sType;
    const struct VkBaseInStructure* pNext;
} VkBaseInStructure;

typedef struct VkAllocationCallbacks {
    void*           pUserData;
    PFN_vkAllocationFunction   pfnAllocation;
    PFN_vkReallocationFunction pfnReallocation;
    PFN_vkFreeFunction    pfnFree;
    PFN_vkInternalAllocationNotification pfnInternalAllocation;
    PFN_vkInternalFreeNotification pfnInternalFree;
} VkAllocationCallbacks;

typedef struct VkDeviceQueueCreateInfo {
    VkStructureType sType;
    const void*     pNext;
    VkDeviceQueueCreateFlags    flags;
    uint32_t        queueFamilyIndex;
    uint32_t        queueCount;
    const float*    pQueuePriorities;
} VkDeviceQueueCreateInfo;

typedef struct VkPhysicalDeviceFeatures {
    VkBool32               robustBufferAccess;
    VkBool32               fullDrawIndexUint32;
    VkBool32               imageCubeArray;
    VkBool32               independentBlend;
    VkBool32               geometryShader;
    VkBool32               tessellationShader;
    VkBool32               sampleRateShading;
    VkBool32               dualSrcBlend;
    VkBool32               logicOp;
    VkBool32               multiDrawIndirect;
    VkBool32               drawIndirectFirstInstance;
    VkBool32               depthClamp;
    VkBool32               depthBiasClamp;
    VkBool32               fillModeNonSolid;
    VkBool32               depthBounds;
    VkBool32               wideLines;
    VkBool32               largePoints;
    VkBool32               alphaToOne;
    VkBool32               multiViewport;
    VkBool32               samplerAnisotropy;
    VkBool32               textureCompressionETC2;
    VkBool32               textureCompressionASTC_LDR;
    VkBool32               textureCompressionBC;
    VkBool32               occlusionQueryPrecise;
    VkBool32               pipelineStatisticsQuery;
    VkBool32               vertexPipelineStoresAndAtomics;
    VkBool32               fragmentStoresAndAtomics;
    VkBool32               shaderTessellationAndGeometryPointSize;
    VkBool32               shaderImageGatherExtended;
    VkBool32               shaderStorageImageExtendedFormats;
    VkBool32               shaderStorageImageMultisample;
    VkBool32               shaderStorageImageReadWithoutFormat;
    VkBool32               shaderStorageImageWriteWithoutFormat;
    VkBool32               shaderUniformBufferArrayDynamicIndexing;
    VkBool32               shaderSampledImageArrayDynamicIndexing;
    VkBool32               shaderStorageBufferArrayDynamicIndexing;
    VkBool32               shaderStorageImageArrayDynamicIndexing;
    VkBool32               shaderClipDistance;
    VkBool32               shaderCullDistance;
    VkBool32               shaderFloat64;
    VkBool32               shaderInt64;
    VkBool32               shaderInt16;
    VkBool32               shaderResourceResidency;
    VkBool32               shaderResourceMinLod;
    VkBool32               sparseBinding;
    VkBool32               sparseResidencyBuffer;
    VkBool32               sparseResidencyImage2D;
    VkBool32               sparseResidencyImage3D;
    VkBool32               sparseResidency2Samples;
    VkBool32               sparseResidency4Samples;
    VkBool32               sparseResidency8Samples;
    VkBool32               sparseResidency16Samples;
    VkBool32               sparseResidencyAliased;
    VkBool32               variableMultisampleRate;
    VkBool32               inheritedQueries;
} VkPhysicalDeviceFeatures;

typedef struct VkDeviceCreateInfo {
    VkStructureType sType;
    const void*     pNext;
    VkDeviceCreateFlags    flags;
    uint32_t        queueCreateInfoCount;
    const VkDeviceQueueCreateInfo* pQueueCreateInfos;
    uint32_t               enabledLayerCount;
    const char* const*      ppEnabledLayerNames;
    uint32_t               enabledExtensionCount;
    const char* const*      ppEnabledExtensionNames;
    const VkPhysicalDeviceFeatures* pEnabledFeatures;
} VkDeviceCreateInfo;

typedef struct VkDrawIndirectCommand {
    uint32_t                       vertexCount;
    uint32_t                       instanceCount;
    uint32_t                       firstVertex;
    uint32_t firstInstance;
} VkDrawIndirectCommand;

typedef struct VkDrawIndexedIndirectCommand {
    uint32_t                       indexCount;
    uint32_t                       instanceCount;
    uint32_t                       firstIndex;
    int32_t                        vertexOffset;
    uint32_t firstInstance;
} VkDrawIndexedIndirectCommand;

typedef struct VkDispatchIndirectCommand {
    uint32_t x;
    uint32_t y;
    uint32_t z;
} VkDispatchIndirectCommand;

typedef struct VkPhysicalDeviceFeatures2 {
    VkStructureType sType;
    void*                            pNext;
    VkPhysicalDeviceFeatures         features;
} VkPhysicalDeviceFeatures2;

typedef struct VkPhysicalDeviceVariablePointersFeatures {
    VkStructureType sType;
    void*                            pNext;
    VkBool32                         variablePointersStorageBuffer;
    VkBool32                         variablePointers;
} VkPhysicalDeviceVariablePointersFeatures;

typedef VkPhysicalDeviceVariablePointersFeatures VkPhysicalDeviceVariablePointerFeatures;

typedef struct VkPhysicalDeviceMultiviewFeatures {
    VkStructureType sType;
    void*                            pNext;
    VkBool32                         multiview;
    VkBool32                         multiviewGeometryShader;
    VkBool32                         multiviewTessellationShader;
} VkPhysicalDeviceMultiviewFeatures;

typedef struct VkDeviceGroupDeviceCreateInfo {
    VkStructureType sType;
    const void*                      pNext;
    uint32_t                         physicalDeviceCount;
    const VkPhysicalDevice*  pPhysicalDevices;
} VkDeviceGroupDeviceCreateInfo;

typedef struct VkPhysicalDevice16BitStorageFeatures {
    VkStructureType sType;
    void*      pNext;
    VkBool32                         storageBuffer16BitAccess;
    VkBool32                         uniformAndStorageBuffer16BitAccess;
    VkBool32                         storagePushConstant16;
    VkBool32                         storageInputOutput16;
} VkPhysicalDevice16BitStorageFeatures;

typedef struct VkPhysicalDeviceSamplerYcbcrConversionFeatures {
    VkStructureType sType;
    void*      pNext;
    VkBool32                         samplerYcbcrConversion;
} VkPhysicalDeviceSamplerYcbcrConversionFeatures;

typedef struct VkPhysicalDeviceProtectedMemoryFeatures {
    VkStructureType sType;
    void*                               pNext;
    VkBool32                            protectedMemory;
} VkPhysicalDeviceProtectedMemoryFeatures;

typedef struct VkPhysicalDeviceShaderDrawParametersFeatures {
    VkStructureType sType;
    void*                            pNext;
    VkBool32                         shaderDrawParameters;
} VkPhysicalDeviceShaderDrawParametersFeatures;

typedef VkPhysicalDeviceShaderDrawParametersFeatures VkPhysicalDeviceShaderDrawParameterFeatures;
