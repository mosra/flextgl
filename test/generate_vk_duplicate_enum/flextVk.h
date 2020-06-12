/* A minimal template to test all corner cases. Not to be used directly. */

#include <stdint.h>
#include <stddef.h>

#define VKAPI_PTR

/* Vulkan 1.2 */

/* Enums */

#define VK_MAX_PHYSICAL_DEVICE_NAME_SIZE 256
#define VK_UUID_SIZE 16
#define VK_LUID_SIZE 8
#define VK_MAX_DRIVER_NAME_SIZE 256
#define VK_MAX_DRIVER_INFO_SIZE 256

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

/* VK_VERSION_1_2 */

#define VK_MAX_DRIVER_NAME_SIZE 256
#define VK_MAX_DRIVER_INFO_SIZE 256

/* VK_KHR_get_physical_device_properties2 */

#define VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_SPEC_VERSION 2
#define VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME "VK_KHR_get_physical_device_properties2"

/* VK_KHR_external_memory_capabilities */

#define VK_KHR_EXTERNAL_MEMORY_CAPABILITIES_SPEC_VERSION 1
#define VK_KHR_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME "VK_KHR_external_memory_capabilities"
#define VK_LUID_SIZE_KHR VK_LUID_SIZE

/* VK_KHR_external_semaphore_capabilities */

#define VK_KHR_EXTERNAL_SEMAPHORE_CAPABILITIES_SPEC_VERSION 1
#define VK_KHR_EXTERNAL_SEMAPHORE_CAPABILITIES_EXTENSION_NAME "VK_KHR_external_semaphore_capabilities"
#define VK_LUID_SIZE_KHR VK_LUID_SIZE

/* VK_KHR_external_fence_capabilities */

#define VK_KHR_EXTERNAL_FENCE_CAPABILITIES_SPEC_VERSION 1
#define VK_KHR_EXTERNAL_FENCE_CAPABILITIES_EXTENSION_NAME "VK_KHR_external_fence_capabilities"
#define VK_LUID_SIZE_KHR VK_LUID_SIZE

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
// Vulkan 1.2 version number
#define VK_API_VERSION_1_2 VK_MAKE_VERSION(1, 2, 0)// Patch version should always be set to 0
// Version of this file
#define VK_HEADER_VERSION 00
// Complete version of this file
#define VK_HEADER_VERSION_COMPLETE VK_MAKE_VERSION(1, 2, VK_HEADER_VERSION)
#define VK_DEFINE_HANDLE(object) typedef struct object##_T* object;
#define VK_NULL_HANDLE 0
typedef uint32_t VkBool32;
typedef uint32_t VkFlags;
typedef uint64_t VkDeviceSize;
typedef VkFlags VkShaderStageFlags;
typedef VkFlags VkSampleCountFlags;
typedef VkFlags VkSubgroupFeatureFlags;
typedef VkFlags VkResolveModeFlags;
VK_DEFINE_HANDLE(VkInstance)
VK_DEFINE_HANDLE(VkPhysicalDevice)
VK_DEFINE_HANDLE(VkDevice)

typedef enum {
    VK_PIPELINE_CACHE_HEADER_VERSION_ONE = 1
} VkPipelineCacheHeaderVersion;

typedef enum {
    VK_PHYSICAL_DEVICE_TYPE_OTHER = 0,
    VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU = 1,
    VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU = 2,
    VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU = 3,
    VK_PHYSICAL_DEVICE_TYPE_CPU = 4
} VkPhysicalDeviceType;

typedef enum {
    VK_SHADER_STAGE_VERTEX_BIT = 1 << 0,
    VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT = 1 << 1,
    VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT = 1 << 2,
    VK_SHADER_STAGE_GEOMETRY_BIT = 1 << 3,
    VK_SHADER_STAGE_FRAGMENT_BIT = 1 << 4,
    VK_SHADER_STAGE_COMPUTE_BIT = 1 << 5,
    VK_SHADER_STAGE_ALL_GRAPHICS = 0x0000001F,
    VK_SHADER_STAGE_ALL = 0x7FFFFFFF
} VkShaderStageFlagBits;

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
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETER_FEATURES = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES = 49,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES = 50,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES = 51,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES = 52,
    VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO = 1000147000,
    VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2 = 1000109000,
    VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2 = 1000109001,
    VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2 = 1000109002,
    VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2 = 1000109003,
    VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2 = 1000109004,
    VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO = 1000109005,
    VK_STRUCTURE_TYPE_SUBPASS_END_INFO = 1000109006,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES = 1000177000,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES = 1000196000,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES = 1000180000,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES = 1000082000,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES = 1000197000,
    VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO = 1000161000,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES = 1000161001,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES = 1000161002,
    VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO = 1000161003,
    VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT = 1000161004,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES = 1000199000,
    VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE = 1000199001,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES = 1000221000,
    VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO = 1000246000,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES = 1000130000,
    VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO = 1000130001,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES = 1000211000,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES = 1000108000,
    VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO = 1000108001,
    VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO = 1000108002,
    VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO = 1000108003,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES = 1000253000,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES = 1000175000,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES = 1000241000,
    VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT = 1000241001,
    VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT = 1000241002,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES = 1000261000,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES = 1000207000,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES = 1000207001,
    VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO = 1000207002,
    VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO = 1000207003,
    VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO = 1000207004,
    VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO = 1000207005,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES = 1000257000,
    VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO = 1000244001,
    VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO = 1000257002,
    VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO = 1000257003,
    VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO = 1000257004,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2,
    VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2_KHR = VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2,
    VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2_KHR = VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2,
    VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2_KHR = VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2,
    VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2_KHR = VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO,
    VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES_KHR = VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO,
    VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES_KHR = VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO,
    VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES_KHR = VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO,
    VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES_KHR = VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES
} VkStructureType;

typedef enum {
    VK_SAMPLE_COUNT_1_BIT = 1 << 0,
    VK_SAMPLE_COUNT_2_BIT = 1 << 1,
    VK_SAMPLE_COUNT_4_BIT = 1 << 2,
    VK_SAMPLE_COUNT_8_BIT = 1 << 3,
    VK_SAMPLE_COUNT_16_BIT = 1 << 4,
    VK_SAMPLE_COUNT_32_BIT = 1 << 5,
    VK_SAMPLE_COUNT_64_BIT = 1 << 6
} VkSampleCountFlagBits;

typedef enum {
    VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES = 0,
    VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY = 1
} VkPointClippingBehavior;

typedef enum {
    VK_RESOLVE_MODE_NONE = 0,
    VK_RESOLVE_MODE_SAMPLE_ZERO_BIT = 1 << 0,
    VK_RESOLVE_MODE_AVERAGE_BIT = 1 << 1,
    VK_RESOLVE_MODE_MIN_BIT = 1 << 2,
    VK_RESOLVE_MODE_MAX_BIT = 1 << 3
} VkResolveModeFlagBits;

typedef enum {
    VK_SUBGROUP_FEATURE_BASIC_BIT = 1 << 0,
    VK_SUBGROUP_FEATURE_VOTE_BIT = 1 << 1,
    VK_SUBGROUP_FEATURE_ARITHMETIC_BIT = 1 << 2,
    VK_SUBGROUP_FEATURE_BALLOT_BIT = 1 << 3,
    VK_SUBGROUP_FEATURE_SHUFFLE_BIT = 1 << 4,
    VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT = 1 << 5,
    VK_SUBGROUP_FEATURE_CLUSTERED_BIT = 1 << 6,
    VK_SUBGROUP_FEATURE_QUAD_BIT = 1 << 7
} VkSubgroupFeatureFlagBits;

typedef enum {
    VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_32_BIT_ONLY = 0,
    VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_ALL = 1,
    VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_NONE = 2
} VkShaderFloatControlsIndependence;

typedef enum {
    VK_VENDOR_ID_VIV = 0x10001,
    VK_VENDOR_ID_VSI = 0x10002,
    VK_VENDOR_ID_KAZAN = 0x10003,
    VK_VENDOR_ID_CODEPLAY = 0x10004
} VkVendorId;

typedef enum {
    VK_DRIVER_ID_AMD_PROPRIETARY = 1,
    VK_DRIVER_ID_AMD_OPEN_SOURCE = 2,
    VK_DRIVER_ID_MESA_RADV = 3,
    VK_DRIVER_ID_NVIDIA_PROPRIETARY = 4,
    VK_DRIVER_ID_INTEL_PROPRIETARY_WINDOWS = 5,
    VK_DRIVER_ID_INTEL_OPEN_SOURCE_MESA = 6,
    VK_DRIVER_ID_IMAGINATION_PROPRIETARY = 7,
    VK_DRIVER_ID_QUALCOMM_PROPRIETARY = 8,
    VK_DRIVER_ID_ARM_PROPRIETARY = 9,
    VK_DRIVER_ID_GOOGLE_SWIFTSHADER = 10,
    VK_DRIVER_ID_GGP_PROPRIETARY = 11,
    VK_DRIVER_ID_BROADCOM_PROPRIETARY = 12
} VkDriverId;
typedef void (VKAPI_PTR *PFN_vkVoidFunction)(void);

typedef struct VkBaseOutStructure {
    VkStructureType sType;
    struct VkBaseOutStructure* pNext;
} VkBaseOutStructure;

typedef struct VkBaseInStructure {
    VkStructureType sType;
    const struct VkBaseInStructure* pNext;
} VkBaseInStructure;

typedef struct VkPhysicalDeviceLimits {
    uint32_t               maxImageDimension1D;
    uint32_t               maxImageDimension2D;
    uint32_t               maxImageDimension3D;
    uint32_t               maxImageDimensionCube;
    uint32_t               maxImageArrayLayers;
    uint32_t               maxTexelBufferElements;
    uint32_t               maxUniformBufferRange;
    uint32_t               maxStorageBufferRange;
    uint32_t               maxPushConstantsSize;
    uint32_t               maxMemoryAllocationCount;
    uint32_t               maxSamplerAllocationCount;
    VkDeviceSize           bufferImageGranularity;
    VkDeviceSize           sparseAddressSpaceSize;
    uint32_t               maxBoundDescriptorSets;
    uint32_t               maxPerStageDescriptorSamplers;
    uint32_t               maxPerStageDescriptorUniformBuffers;
    uint32_t               maxPerStageDescriptorStorageBuffers;
    uint32_t               maxPerStageDescriptorSampledImages;
    uint32_t               maxPerStageDescriptorStorageImages;
    uint32_t               maxPerStageDescriptorInputAttachments;
    uint32_t               maxPerStageResources;
    uint32_t               maxDescriptorSetSamplers;
    uint32_t               maxDescriptorSetUniformBuffers;
    uint32_t               maxDescriptorSetUniformBuffersDynamic;
    uint32_t               maxDescriptorSetStorageBuffers;
    uint32_t               maxDescriptorSetStorageBuffersDynamic;
    uint32_t               maxDescriptorSetSampledImages;
    uint32_t               maxDescriptorSetStorageImages;
    uint32_t               maxDescriptorSetInputAttachments;
    uint32_t               maxVertexInputAttributes;
    uint32_t               maxVertexInputBindings;
    uint32_t               maxVertexInputAttributeOffset;
    uint32_t               maxVertexInputBindingStride;
    uint32_t               maxVertexOutputComponents;
    uint32_t               maxTessellationGenerationLevel;
    uint32_t               maxTessellationPatchSize;
    uint32_t               maxTessellationControlPerVertexInputComponents;
    uint32_t               maxTessellationControlPerVertexOutputComponents;
    uint32_t               maxTessellationControlPerPatchOutputComponents;
    uint32_t               maxTessellationControlTotalOutputComponents;
    uint32_t               maxTessellationEvaluationInputComponents;
    uint32_t               maxTessellationEvaluationOutputComponents;
    uint32_t               maxGeometryShaderInvocations;
    uint32_t               maxGeometryInputComponents;
    uint32_t               maxGeometryOutputComponents;
    uint32_t               maxGeometryOutputVertices;
    uint32_t               maxGeometryTotalOutputComponents;
    uint32_t               maxFragmentInputComponents;
    uint32_t               maxFragmentOutputAttachments;
    uint32_t               maxFragmentDualSrcAttachments;
    uint32_t               maxFragmentCombinedOutputResources;
    uint32_t               maxComputeSharedMemorySize;
    uint32_t               maxComputeWorkGroupCount[3];
    uint32_t               maxComputeWorkGroupInvocations;
    uint32_t               maxComputeWorkGroupSize[3];
    uint32_t               subPixelPrecisionBits;
    uint32_t               subTexelPrecisionBits;
    uint32_t               mipmapPrecisionBits;
    uint32_t               maxDrawIndexedIndexValue;
    uint32_t               maxDrawIndirectCount;
    float                  maxSamplerLodBias;
    float                  maxSamplerAnisotropy;
    uint32_t               maxViewports;
    uint32_t               maxViewportDimensions[2];
    float                  viewportBoundsRange[2];
    uint32_t               viewportSubPixelBits;
    size_t                 minMemoryMapAlignment;
    VkDeviceSize           minTexelBufferOffsetAlignment;
    VkDeviceSize           minUniformBufferOffsetAlignment;
    VkDeviceSize           minStorageBufferOffsetAlignment;
    int32_t                minTexelOffset;
    uint32_t               maxTexelOffset;
    int32_t                minTexelGatherOffset;
    uint32_t               maxTexelGatherOffset;
    float                  minInterpolationOffset;
    float                  maxInterpolationOffset;
    uint32_t               subPixelInterpolationOffsetBits;
    uint32_t               maxFramebufferWidth;
    uint32_t               maxFramebufferHeight;
    uint32_t               maxFramebufferLayers;
    VkSampleCountFlags     framebufferColorSampleCounts;
    VkSampleCountFlags     framebufferDepthSampleCounts;
    VkSampleCountFlags     framebufferStencilSampleCounts;
    VkSampleCountFlags     framebufferNoAttachmentsSampleCounts;
    uint32_t               maxColorAttachments;
    VkSampleCountFlags     sampledImageColorSampleCounts;
    VkSampleCountFlags     sampledImageIntegerSampleCounts;
    VkSampleCountFlags     sampledImageDepthSampleCounts;
    VkSampleCountFlags     sampledImageStencilSampleCounts;
    VkSampleCountFlags     storageImageSampleCounts;
    uint32_t               maxSampleMaskWords;
    VkBool32               timestampComputeAndGraphics;
    float                  timestampPeriod;
    uint32_t               maxClipDistances;
    uint32_t               maxCullDistances;
    uint32_t               maxCombinedClipAndCullDistances;
    uint32_t               discreteQueuePriorities;
    float                  pointSizeRange[2];
    float                  lineWidthRange[2];
    float                  pointSizeGranularity;
    float                  lineWidthGranularity;
    VkBool32               strictLines;
    VkBool32               standardSampleLocations;
    VkDeviceSize           optimalBufferCopyOffsetAlignment;
    VkDeviceSize           optimalBufferCopyRowPitchAlignment;
    VkDeviceSize           nonCoherentAtomSize;
} VkPhysicalDeviceLimits;

typedef struct VkPhysicalDeviceSparseProperties {
    VkBool32               residencyStandard2DBlockShape;
    VkBool32               residencyStandard2DMultisampleBlockShape;
    VkBool32               residencyStandard3DBlockShape;
    VkBool32               residencyAlignedMipSize;
    VkBool32               residencyNonResidentStrict;
} VkPhysicalDeviceSparseProperties;

typedef struct VkPhysicalDeviceProperties {
    uint32_t       apiVersion;
    uint32_t       driverVersion;
    uint32_t       vendorID;
    uint32_t       deviceID;
    VkPhysicalDeviceType deviceType;
    char           deviceName[VK_MAX_PHYSICAL_DEVICE_NAME_SIZE];
    uint8_t        pipelineCacheUUID[VK_UUID_SIZE];
    VkPhysicalDeviceLimits limits;
    VkPhysicalDeviceSparseProperties sparseProperties;
} VkPhysicalDeviceProperties;

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

typedef struct VkPhysicalDeviceProperties2 {
    VkStructureType sType;
    void*                            pNext;
    VkPhysicalDeviceProperties       properties;
} VkPhysicalDeviceProperties2;

typedef VkPhysicalDeviceProperties2 VkPhysicalDeviceProperties2KHR;

typedef struct VkConformanceVersion {
    uint8_t                          major;
    uint8_t                          minor;
    uint8_t                          subminor;
    uint8_t                          patch;
} VkConformanceVersion;

typedef struct VkPhysicalDeviceDriverProperties {
    VkStructureType sType;
    void*                            pNext;
    VkDriverId                       driverID;
    char                             driverName[VK_MAX_DRIVER_NAME_SIZE];
    char                             driverInfo[VK_MAX_DRIVER_INFO_SIZE];
    VkConformanceVersion             conformanceVersion;
} VkPhysicalDeviceDriverProperties;

typedef struct VkPhysicalDeviceIDProperties {
    VkStructureType sType;
    void*                            pNext;
    uint8_t                          deviceUUID[VK_UUID_SIZE];
    uint8_t                          driverUUID[VK_UUID_SIZE];
    uint8_t                          deviceLUID[VK_LUID_SIZE];
    uint32_t                         deviceNodeMask;
    VkBool32                         deviceLUIDValid;
} VkPhysicalDeviceIDProperties;

typedef VkPhysicalDeviceIDProperties VkPhysicalDeviceIDPropertiesKHR;

typedef struct VkPhysicalDeviceMultiviewProperties {
    VkStructureType sType;
    void*                            pNext;
    uint32_t                         maxMultiviewViewCount;
    uint32_t                         maxMultiviewInstanceIndex;
} VkPhysicalDeviceMultiviewProperties;

typedef struct VkPhysicalDeviceSubgroupProperties {
    VkStructureType sType;
    void*                   pNext;
    uint32_t                      subgroupSize;
    VkShaderStageFlags            supportedStages;
    VkSubgroupFeatureFlags        supportedOperations;
    VkBool32 quadOperationsInAllStages;
} VkPhysicalDeviceSubgroupProperties;

typedef struct VkPhysicalDevicePointClippingProperties {
    VkStructureType sType;
    void*                            pNext;
    VkPointClippingBehavior      pointClippingBehavior;
} VkPhysicalDevicePointClippingProperties;

typedef struct VkPhysicalDeviceProtectedMemoryProperties {
    VkStructureType sType;
    void*                               pNext;
    VkBool32                            protectedNoFault;
} VkPhysicalDeviceProtectedMemoryProperties;

typedef struct VkPhysicalDeviceSamplerFilterMinmaxProperties {
    VkStructureType sType;
    void*                  pNext;
    VkBool32               filterMinmaxSingleComponentFormats;
    VkBool32               filterMinmaxImageComponentMapping;
} VkPhysicalDeviceSamplerFilterMinmaxProperties;

typedef struct VkPhysicalDeviceMaintenance3Properties {
    VkStructureType sType;
    void*                            pNext;
    uint32_t                         maxPerSetDescriptors;
    VkDeviceSize                     maxMemoryAllocationSize;
} VkPhysicalDeviceMaintenance3Properties;

typedef struct VkPhysicalDeviceFloatControlsProperties {
    VkStructureType sType;
    void*                            pNext;
    VkShaderFloatControlsIndependence denormBehaviorIndependence;
    VkShaderFloatControlsIndependence roundingModeIndependence;
    VkBool32                         shaderSignedZeroInfNanPreserveFloat16;
    VkBool32                         shaderSignedZeroInfNanPreserveFloat32;
    VkBool32                         shaderSignedZeroInfNanPreserveFloat64;
    VkBool32                         shaderDenormPreserveFloat16;
    VkBool32                         shaderDenormPreserveFloat32;
    VkBool32                         shaderDenormPreserveFloat64;
    VkBool32                         shaderDenormFlushToZeroFloat16;
    VkBool32                         shaderDenormFlushToZeroFloat32;
    VkBool32                         shaderDenormFlushToZeroFloat64;
    VkBool32                         shaderRoundingModeRTEFloat16;
    VkBool32                         shaderRoundingModeRTEFloat32;
    VkBool32                         shaderRoundingModeRTEFloat64;
    VkBool32                         shaderRoundingModeRTZFloat16;
    VkBool32                         shaderRoundingModeRTZFloat32;
    VkBool32                         shaderRoundingModeRTZFloat64;
} VkPhysicalDeviceFloatControlsProperties;

typedef struct VkPhysicalDeviceDescriptorIndexingProperties {
    VkStructureType sType;
    void*                            pNext;
    uint32_t               maxUpdateAfterBindDescriptorsInAllPools;
    VkBool32               shaderUniformBufferArrayNonUniformIndexingNative;
    VkBool32               shaderSampledImageArrayNonUniformIndexingNative;
    VkBool32               shaderStorageBufferArrayNonUniformIndexingNative;
    VkBool32               shaderStorageImageArrayNonUniformIndexingNative;
    VkBool32               shaderInputAttachmentArrayNonUniformIndexingNative;
    VkBool32               robustBufferAccessUpdateAfterBind;
    VkBool32               quadDivergentImplicitLod;
    uint32_t               maxPerStageDescriptorUpdateAfterBindSamplers;
    uint32_t               maxPerStageDescriptorUpdateAfterBindUniformBuffers;
    uint32_t               maxPerStageDescriptorUpdateAfterBindStorageBuffers;
    uint32_t               maxPerStageDescriptorUpdateAfterBindSampledImages;
    uint32_t               maxPerStageDescriptorUpdateAfterBindStorageImages;
    uint32_t               maxPerStageDescriptorUpdateAfterBindInputAttachments;
    uint32_t               maxPerStageUpdateAfterBindResources;
    uint32_t               maxDescriptorSetUpdateAfterBindSamplers;
    uint32_t               maxDescriptorSetUpdateAfterBindUniformBuffers;
    uint32_t               maxDescriptorSetUpdateAfterBindUniformBuffersDynamic;
    uint32_t               maxDescriptorSetUpdateAfterBindStorageBuffers;
    uint32_t               maxDescriptorSetUpdateAfterBindStorageBuffersDynamic;
    uint32_t               maxDescriptorSetUpdateAfterBindSampledImages;
    uint32_t               maxDescriptorSetUpdateAfterBindStorageImages;
    uint32_t               maxDescriptorSetUpdateAfterBindInputAttachments;
} VkPhysicalDeviceDescriptorIndexingProperties;

typedef struct VkPhysicalDeviceTimelineSemaphoreProperties {
    VkStructureType sType;
    void*                  pNext;
    uint64_t               maxTimelineSemaphoreValueDifference;
} VkPhysicalDeviceTimelineSemaphoreProperties;

typedef struct VkPhysicalDeviceDepthStencilResolveProperties {
    VkStructureType sType;
    void*                                pNext;
    VkResolveModeFlags                   supportedDepthResolveModes;
    VkResolveModeFlags                   supportedStencilResolveModes;
    VkBool32                             independentResolveNone;
    VkBool32                             independentResolve;
} VkPhysicalDeviceDepthStencilResolveProperties;

typedef struct VkPhysicalDeviceVulkan11Properties {
    VkStructureType sType;
    void*      pNext;
    uint8_t                          deviceUUID[VK_UUID_SIZE];
    uint8_t                          driverUUID[VK_UUID_SIZE];
    uint8_t                          deviceLUID[VK_LUID_SIZE];
    uint32_t                         deviceNodeMask;
    VkBool32                         deviceLUIDValid;
    uint32_t                      subgroupSize;
    VkShaderStageFlags            subgroupSupportedStages;
    VkSubgroupFeatureFlags        subgroupSupportedOperations;
    VkBool32                      subgroupQuadOperationsInAllStages;
    VkPointClippingBehavior          pointClippingBehavior;
    uint32_t                         maxMultiviewViewCount;
    uint32_t                         maxMultiviewInstanceIndex;
    VkBool32                         protectedNoFault;
    uint32_t                         maxPerSetDescriptors;
    VkDeviceSize                     maxMemoryAllocationSize;
} VkPhysicalDeviceVulkan11Properties;

typedef struct VkPhysicalDeviceVulkan12Properties {
    VkStructureType sType;
    void*    pNext;
    VkDriverId                       driverID;
    char                             driverName[VK_MAX_DRIVER_NAME_SIZE];
    char                             driverInfo[VK_MAX_DRIVER_INFO_SIZE];
    VkConformanceVersion             conformanceVersion;
    VkShaderFloatControlsIndependence denormBehaviorIndependence;
    VkShaderFloatControlsIndependence roundingModeIndependence;
    VkBool32                         shaderSignedZeroInfNanPreserveFloat16;
    VkBool32                         shaderSignedZeroInfNanPreserveFloat32;
    VkBool32                         shaderSignedZeroInfNanPreserveFloat64;
    VkBool32                         shaderDenormPreserveFloat16;
    VkBool32                         shaderDenormPreserveFloat32;
    VkBool32                         shaderDenormPreserveFloat64;
    VkBool32                         shaderDenormFlushToZeroFloat16;
    VkBool32                         shaderDenormFlushToZeroFloat32;
    VkBool32                         shaderDenormFlushToZeroFloat64;
    VkBool32                         shaderRoundingModeRTEFloat16;
    VkBool32                         shaderRoundingModeRTEFloat32;
    VkBool32                         shaderRoundingModeRTEFloat64;
    VkBool32                         shaderRoundingModeRTZFloat16;
    VkBool32                         shaderRoundingModeRTZFloat32;
    VkBool32                         shaderRoundingModeRTZFloat64;
    uint32_t                         maxUpdateAfterBindDescriptorsInAllPools;
    VkBool32                         shaderUniformBufferArrayNonUniformIndexingNative;
    VkBool32                         shaderSampledImageArrayNonUniformIndexingNative;
    VkBool32                         shaderStorageBufferArrayNonUniformIndexingNative;
    VkBool32                         shaderStorageImageArrayNonUniformIndexingNative;
    VkBool32                         shaderInputAttachmentArrayNonUniformIndexingNative;
    VkBool32                         robustBufferAccessUpdateAfterBind;
    VkBool32                         quadDivergentImplicitLod;
    uint32_t                         maxPerStageDescriptorUpdateAfterBindSamplers;
    uint32_t                         maxPerStageDescriptorUpdateAfterBindUniformBuffers;
    uint32_t                         maxPerStageDescriptorUpdateAfterBindStorageBuffers;
    uint32_t                         maxPerStageDescriptorUpdateAfterBindSampledImages;
    uint32_t                         maxPerStageDescriptorUpdateAfterBindStorageImages;
    uint32_t                         maxPerStageDescriptorUpdateAfterBindInputAttachments;
    uint32_t                         maxPerStageUpdateAfterBindResources;
    uint32_t                         maxDescriptorSetUpdateAfterBindSamplers;
    uint32_t                         maxDescriptorSetUpdateAfterBindUniformBuffers;
    uint32_t                         maxDescriptorSetUpdateAfterBindUniformBuffersDynamic;
    uint32_t                         maxDescriptorSetUpdateAfterBindStorageBuffers;
    uint32_t                         maxDescriptorSetUpdateAfterBindStorageBuffersDynamic;
    uint32_t                         maxDescriptorSetUpdateAfterBindSampledImages;
    uint32_t                         maxDescriptorSetUpdateAfterBindStorageImages;
    uint32_t                         maxDescriptorSetUpdateAfterBindInputAttachments;
    VkResolveModeFlags               supportedDepthResolveModes;
    VkResolveModeFlags               supportedStencilResolveModes;
    VkBool32                         independentResolveNone;
    VkBool32                         independentResolve;
    VkBool32                         filterMinmaxSingleComponentFormats;
    VkBool32                         filterMinmaxImageComponentMapping;
    uint64_t                         maxTimelineSemaphoreValueDifference;
    VkSampleCountFlags framebufferIntegerColorSampleCounts;
} VkPhysicalDeviceVulkan12Properties;
