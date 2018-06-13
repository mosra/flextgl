/* A minimal template to test all corner cases. Not to be used directly. */

#include <stdint.h>
#include <stddef.h>

#define VKAPI_PTR

/* Vulkan 1.0 */

/* Enums */

#define VK_MAX_PHYSICAL_DEVICE_NAME_SIZE 256
#define VK_UUID_SIZE 16
#define VK_QUEUE_FAMILY_EXTERNAL (~0U-1)

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

/* VK_NV_dedicated_allocation */

#define VK_NV_DEDICATED_ALLOCATION_SPEC_VERSION 1
#define VK_NV_DEDICATED_ALLOCATION_EXTENSION_NAME "VK_NV_dedicated_allocation"

/* VK_KHR_swapchain */

#define VK_KHR_SWAPCHAIN_SPEC_VERSION 70
#define VK_KHR_SWAPCHAIN_EXTENSION_NAME "VK_KHR_swapchain"

/* VK_KHR_sampler_mirror_clamp_to_edge */

#define VK_KHR_SAMPLER_MIRROR_CLAMP_TO_EDGE_SPEC_VERSION 1
#define VK_KHR_SAMPLER_MIRROR_CLAMP_TO_EDGE_EXTENSION_NAME "VK_KHR_sampler_mirror_clamp_to_edge"

/* VK_IMG_filter_cubic */

#define VK_IMG_FILTER_CUBIC_SPEC_VERSION 1
#define VK_IMG_FILTER_CUBIC_EXTENSION_NAME "VK_IMG_filter_cubic"

/* VK_KHR_external_memory */

#define VK_KHR_EXTERNAL_MEMORY_SPEC_VERSION 1
#define VK_KHR_EXTERNAL_MEMORY_EXTENSION_NAME "VK_KHR_external_memory"
#define VK_QUEUE_FAMILY_EXTERNAL_KHR VK_QUEUE_FAMILY_EXTERNAL

/* VK_KHR_get_physical_device_properties2 */

#define VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_SPEC_VERSION 1
#define VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME "VK_KHR_get_physical_device_properties2"

/* Data types */

#define VK_MAKE_VERSION(major, minor, patch) \
    (((major) << 22) | ((minor) << 12) | (patch))
#define VK_VERSION_MAJOR(version) ((uint32_t)(version) >> 22)
#define VK_VERSION_MINOR(version) (((uint32_t)(version) >> 12) & 0x3ff)
#define VK_VERSION_PATCH(version) ((uint32_t)(version) & 0xfff)
// Vulkan 1.0 version number
#define VK_API_VERSION_1_0 VK_MAKE_VERSION(1, 0, 0)// Patch version should always be set to 0
// Version of this file
#define VK_HEADER_VERSION 77
#define VK_DEFINE_HANDLE(object) typedef struct object##_T* object;
#if !defined(VK_DEFINE_NON_DISPATCHABLE_HANDLE)
#if defined(__LP64__) || defined(_WIN64) || (defined(__x86_64__) && !defined(__ILP32__) ) || defined(_M_X64) || defined(__ia64) || defined (_M_IA64) || defined(__aarch64__) || defined(__powerpc64__)
        #define VK_DEFINE_NON_DISPATCHABLE_HANDLE(object) typedef struct object##_T *object;
#else
        #define VK_DEFINE_NON_DISPATCHABLE_HANDLE(object) typedef uint64_t object;
#endif
#endif
#define VK_NULL_HANDLE 0
typedef uint32_t VkBool32;
typedef uint32_t VkFlags;
typedef uint64_t VkDeviceSize;
typedef VkFlags VkSamplerCreateFlags;
typedef VkFlags VkBufferViewCreateFlags;
typedef VkFlags VkBufferUsageFlags;
typedef VkFlags VkBufferCreateFlags;
typedef VkFlags VkFormatFeatureFlags;
typedef VkFlags VkSampleCountFlags;
typedef VkFlags VkExternalMemoryHandleTypeFlags;
VK_DEFINE_HANDLE(VkInstance)
VK_DEFINE_HANDLE(VkPhysicalDevice)
VK_DEFINE_HANDLE(VkDevice)
VK_DEFINE_HANDLE(VkCommandBuffer)
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkBuffer)
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkBufferView)
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkSampler)

typedef enum {
    VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK = 0,
    VK_BORDER_COLOR_INT_TRANSPARENT_BLACK = 1,
    VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK = 2,
    VK_BORDER_COLOR_INT_OPAQUE_BLACK = 3,
    VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE = 4,
    VK_BORDER_COLOR_INT_OPAQUE_WHITE = 5
} VkBorderColor;

typedef enum {
    VK_PIPELINE_CACHE_HEADER_VERSION_ONE = 1
} VkPipelineCacheHeaderVersion;

typedef enum {
    VK_BUFFER_CREATE_SPARSE_BINDING_BIT = 1 << 0,
    VK_BUFFER_CREATE_SPARSE_RESIDENCY_BIT = 1 << 1,
    VK_BUFFER_CREATE_SPARSE_ALIASED_BIT = 1 << 2
} VkBufferCreateFlagBits;

typedef enum {
    VK_BUFFER_USAGE_TRANSFER_SRC_BIT = 1 << 0,
    VK_BUFFER_USAGE_TRANSFER_DST_BIT = 1 << 1,
    VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT = 1 << 2,
    VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT = 1 << 3,
    VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT = 1 << 4,
    VK_BUFFER_USAGE_STORAGE_BUFFER_BIT = 1 << 5,
    VK_BUFFER_USAGE_INDEX_BUFFER_BIT = 1 << 6,
    VK_BUFFER_USAGE_VERTEX_BUFFER_BIT = 1 << 7,
    VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT = 1 << 8
} VkBufferUsageFlagBits;

typedef enum {
    VK_COMPARE_OP_NEVER = 0,
    VK_COMPARE_OP_LESS = 1,
    VK_COMPARE_OP_EQUAL = 2,
    VK_COMPARE_OP_LESS_OR_EQUAL = 3,
    VK_COMPARE_OP_GREATER = 4,
    VK_COMPARE_OP_NOT_EQUAL = 5,
    VK_COMPARE_OP_GREATER_OR_EQUAL = 6,
    VK_COMPARE_OP_ALWAYS = 7
} VkCompareOp;

typedef enum {
    VK_FORMAT_UNDEFINED = 0,
    VK_FORMAT_R4G4_UNORM_PACK8 = 1,
    VK_FORMAT_R4G4B4A4_UNORM_PACK16 = 2,
    VK_FORMAT_B4G4R4A4_UNORM_PACK16 = 3,
    VK_FORMAT_R5G6B5_UNORM_PACK16 = 4,
    VK_FORMAT_B5G6R5_UNORM_PACK16 = 5,
    VK_FORMAT_R5G5B5A1_UNORM_PACK16 = 6,
    VK_FORMAT_B5G5R5A1_UNORM_PACK16 = 7,
    VK_FORMAT_A1R5G5B5_UNORM_PACK16 = 8,
    VK_FORMAT_R8_UNORM = 9,
    VK_FORMAT_R8_SNORM = 10,
    VK_FORMAT_R8_USCALED = 11,
    VK_FORMAT_R8_SSCALED = 12,
    VK_FORMAT_R8_UINT = 13,
    VK_FORMAT_R8_SINT = 14,
    VK_FORMAT_R8_SRGB = 15,
    VK_FORMAT_R8G8_UNORM = 16,
    VK_FORMAT_R8G8_SNORM = 17,
    VK_FORMAT_R8G8_USCALED = 18,
    VK_FORMAT_R8G8_SSCALED = 19,
    VK_FORMAT_R8G8_UINT = 20,
    VK_FORMAT_R8G8_SINT = 21,
    VK_FORMAT_R8G8_SRGB = 22,
    VK_FORMAT_R8G8B8_UNORM = 23,
    VK_FORMAT_R8G8B8_SNORM = 24,
    VK_FORMAT_R8G8B8_USCALED = 25,
    VK_FORMAT_R8G8B8_SSCALED = 26,
    VK_FORMAT_R8G8B8_UINT = 27,
    VK_FORMAT_R8G8B8_SINT = 28,
    VK_FORMAT_R8G8B8_SRGB = 29,
    VK_FORMAT_B8G8R8_UNORM = 30,
    VK_FORMAT_B8G8R8_SNORM = 31,
    VK_FORMAT_B8G8R8_USCALED = 32,
    VK_FORMAT_B8G8R8_SSCALED = 33,
    VK_FORMAT_B8G8R8_UINT = 34,
    VK_FORMAT_B8G8R8_SINT = 35,
    VK_FORMAT_B8G8R8_SRGB = 36,
    VK_FORMAT_R8G8B8A8_UNORM = 37,
    VK_FORMAT_R8G8B8A8_SNORM = 38,
    VK_FORMAT_R8G8B8A8_USCALED = 39,
    VK_FORMAT_R8G8B8A8_SSCALED = 40,
    VK_FORMAT_R8G8B8A8_UINT = 41,
    VK_FORMAT_R8G8B8A8_SINT = 42,
    VK_FORMAT_R8G8B8A8_SRGB = 43,
    VK_FORMAT_B8G8R8A8_UNORM = 44,
    VK_FORMAT_B8G8R8A8_SNORM = 45,
    VK_FORMAT_B8G8R8A8_USCALED = 46,
    VK_FORMAT_B8G8R8A8_SSCALED = 47,
    VK_FORMAT_B8G8R8A8_UINT = 48,
    VK_FORMAT_B8G8R8A8_SINT = 49,
    VK_FORMAT_B8G8R8A8_SRGB = 50,
    VK_FORMAT_A8B8G8R8_UNORM_PACK32 = 51,
    VK_FORMAT_A8B8G8R8_SNORM_PACK32 = 52,
    VK_FORMAT_A8B8G8R8_USCALED_PACK32 = 53,
    VK_FORMAT_A8B8G8R8_SSCALED_PACK32 = 54,
    VK_FORMAT_A8B8G8R8_UINT_PACK32 = 55,
    VK_FORMAT_A8B8G8R8_SINT_PACK32 = 56,
    VK_FORMAT_A8B8G8R8_SRGB_PACK32 = 57,
    VK_FORMAT_A2R10G10B10_UNORM_PACK32 = 58,
    VK_FORMAT_A2R10G10B10_SNORM_PACK32 = 59,
    VK_FORMAT_A2R10G10B10_USCALED_PACK32 = 60,
    VK_FORMAT_A2R10G10B10_SSCALED_PACK32 = 61,
    VK_FORMAT_A2R10G10B10_UINT_PACK32 = 62,
    VK_FORMAT_A2R10G10B10_SINT_PACK32 = 63,
    VK_FORMAT_A2B10G10R10_UNORM_PACK32 = 64,
    VK_FORMAT_A2B10G10R10_SNORM_PACK32 = 65,
    VK_FORMAT_A2B10G10R10_USCALED_PACK32 = 66,
    VK_FORMAT_A2B10G10R10_SSCALED_PACK32 = 67,
    VK_FORMAT_A2B10G10R10_UINT_PACK32 = 68,
    VK_FORMAT_A2B10G10R10_SINT_PACK32 = 69,
    VK_FORMAT_R16_UNORM = 70,
    VK_FORMAT_R16_SNORM = 71,
    VK_FORMAT_R16_USCALED = 72,
    VK_FORMAT_R16_SSCALED = 73,
    VK_FORMAT_R16_UINT = 74,
    VK_FORMAT_R16_SINT = 75,
    VK_FORMAT_R16_SFLOAT = 76,
    VK_FORMAT_R16G16_UNORM = 77,
    VK_FORMAT_R16G16_SNORM = 78,
    VK_FORMAT_R16G16_USCALED = 79,
    VK_FORMAT_R16G16_SSCALED = 80,
    VK_FORMAT_R16G16_UINT = 81,
    VK_FORMAT_R16G16_SINT = 82,
    VK_FORMAT_R16G16_SFLOAT = 83,
    VK_FORMAT_R16G16B16_UNORM = 84,
    VK_FORMAT_R16G16B16_SNORM = 85,
    VK_FORMAT_R16G16B16_USCALED = 86,
    VK_FORMAT_R16G16B16_SSCALED = 87,
    VK_FORMAT_R16G16B16_UINT = 88,
    VK_FORMAT_R16G16B16_SINT = 89,
    VK_FORMAT_R16G16B16_SFLOAT = 90,
    VK_FORMAT_R16G16B16A16_UNORM = 91,
    VK_FORMAT_R16G16B16A16_SNORM = 92,
    VK_FORMAT_R16G16B16A16_USCALED = 93,
    VK_FORMAT_R16G16B16A16_SSCALED = 94,
    VK_FORMAT_R16G16B16A16_UINT = 95,
    VK_FORMAT_R16G16B16A16_SINT = 96,
    VK_FORMAT_R16G16B16A16_SFLOAT = 97,
    VK_FORMAT_R32_UINT = 98,
    VK_FORMAT_R32_SINT = 99,
    VK_FORMAT_R32_SFLOAT = 100,
    VK_FORMAT_R32G32_UINT = 101,
    VK_FORMAT_R32G32_SINT = 102,
    VK_FORMAT_R32G32_SFLOAT = 103,
    VK_FORMAT_R32G32B32_UINT = 104,
    VK_FORMAT_R32G32B32_SINT = 105,
    VK_FORMAT_R32G32B32_SFLOAT = 106,
    VK_FORMAT_R32G32B32A32_UINT = 107,
    VK_FORMAT_R32G32B32A32_SINT = 108,
    VK_FORMAT_R32G32B32A32_SFLOAT = 109,
    VK_FORMAT_R64_UINT = 110,
    VK_FORMAT_R64_SINT = 111,
    VK_FORMAT_R64_SFLOAT = 112,
    VK_FORMAT_R64G64_UINT = 113,
    VK_FORMAT_R64G64_SINT = 114,
    VK_FORMAT_R64G64_SFLOAT = 115,
    VK_FORMAT_R64G64B64_UINT = 116,
    VK_FORMAT_R64G64B64_SINT = 117,
    VK_FORMAT_R64G64B64_SFLOAT = 118,
    VK_FORMAT_R64G64B64A64_UINT = 119,
    VK_FORMAT_R64G64B64A64_SINT = 120,
    VK_FORMAT_R64G64B64A64_SFLOAT = 121,
    VK_FORMAT_B10G11R11_UFLOAT_PACK32 = 122,
    VK_FORMAT_E5B9G9R9_UFLOAT_PACK32 = 123,
    VK_FORMAT_D16_UNORM = 124,
    VK_FORMAT_X8_D24_UNORM_PACK32 = 125,
    VK_FORMAT_D32_SFLOAT = 126,
    VK_FORMAT_S8_UINT = 127,
    VK_FORMAT_D16_UNORM_S8_UINT = 128,
    VK_FORMAT_D24_UNORM_S8_UINT = 129,
    VK_FORMAT_D32_SFLOAT_S8_UINT = 130,
    VK_FORMAT_BC1_RGB_UNORM_BLOCK = 131,
    VK_FORMAT_BC1_RGB_SRGB_BLOCK = 132,
    VK_FORMAT_BC1_RGBA_UNORM_BLOCK = 133,
    VK_FORMAT_BC1_RGBA_SRGB_BLOCK = 134,
    VK_FORMAT_BC2_UNORM_BLOCK = 135,
    VK_FORMAT_BC2_SRGB_BLOCK = 136,
    VK_FORMAT_BC3_UNORM_BLOCK = 137,
    VK_FORMAT_BC3_SRGB_BLOCK = 138,
    VK_FORMAT_BC4_UNORM_BLOCK = 139,
    VK_FORMAT_BC4_SNORM_BLOCK = 140,
    VK_FORMAT_BC5_UNORM_BLOCK = 141,
    VK_FORMAT_BC5_SNORM_BLOCK = 142,
    VK_FORMAT_BC6H_UFLOAT_BLOCK = 143,
    VK_FORMAT_BC6H_SFLOAT_BLOCK = 144,
    VK_FORMAT_BC7_UNORM_BLOCK = 145,
    VK_FORMAT_BC7_SRGB_BLOCK = 146,
    VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK = 147,
    VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK = 148,
    VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK = 149,
    VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK = 150,
    VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK = 151,
    VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK = 152,
    VK_FORMAT_EAC_R11_UNORM_BLOCK = 153,
    VK_FORMAT_EAC_R11_SNORM_BLOCK = 154,
    VK_FORMAT_EAC_R11G11_UNORM_BLOCK = 155,
    VK_FORMAT_EAC_R11G11_SNORM_BLOCK = 156,
    VK_FORMAT_ASTC_4x4_UNORM_BLOCK = 157,
    VK_FORMAT_ASTC_4x4_SRGB_BLOCK = 158,
    VK_FORMAT_ASTC_5x4_UNORM_BLOCK = 159,
    VK_FORMAT_ASTC_5x4_SRGB_BLOCK = 160,
    VK_FORMAT_ASTC_5x5_UNORM_BLOCK = 161,
    VK_FORMAT_ASTC_5x5_SRGB_BLOCK = 162,
    VK_FORMAT_ASTC_6x5_UNORM_BLOCK = 163,
    VK_FORMAT_ASTC_6x5_SRGB_BLOCK = 164,
    VK_FORMAT_ASTC_6x6_UNORM_BLOCK = 165,
    VK_FORMAT_ASTC_6x6_SRGB_BLOCK = 166,
    VK_FORMAT_ASTC_8x5_UNORM_BLOCK = 167,
    VK_FORMAT_ASTC_8x5_SRGB_BLOCK = 168,
    VK_FORMAT_ASTC_8x6_UNORM_BLOCK = 169,
    VK_FORMAT_ASTC_8x6_SRGB_BLOCK = 170,
    VK_FORMAT_ASTC_8x8_UNORM_BLOCK = 171,
    VK_FORMAT_ASTC_8x8_SRGB_BLOCK = 172,
    VK_FORMAT_ASTC_10x5_UNORM_BLOCK = 173,
    VK_FORMAT_ASTC_10x5_SRGB_BLOCK = 174,
    VK_FORMAT_ASTC_10x6_UNORM_BLOCK = 175,
    VK_FORMAT_ASTC_10x6_SRGB_BLOCK = 176,
    VK_FORMAT_ASTC_10x8_UNORM_BLOCK = 177,
    VK_FORMAT_ASTC_10x8_SRGB_BLOCK = 178,
    VK_FORMAT_ASTC_10x10_UNORM_BLOCK = 179,
    VK_FORMAT_ASTC_10x10_SRGB_BLOCK = 180,
    VK_FORMAT_ASTC_12x10_UNORM_BLOCK = 181,
    VK_FORMAT_ASTC_12x10_SRGB_BLOCK = 182,
    VK_FORMAT_ASTC_12x12_UNORM_BLOCK = 183,
    VK_FORMAT_ASTC_12x12_SRGB_BLOCK = 184
} VkFormat;

typedef enum {
    VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT = 1 << 0,
    VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT = 1 << 1,
    VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT = 1 << 2,
    VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT = 1 << 3,
    VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT = 1 << 4,
    VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT = 1 << 5,
    VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT = 1 << 6,
    VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT = 1 << 7,
    VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT = 1 << 8,
    VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT = 1 << 9,
    VK_FORMAT_FEATURE_BLIT_SRC_BIT = 1 << 10,
    VK_FORMAT_FEATURE_BLIT_DST_BIT = 1 << 11,
    VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT = 1 << 12,
    VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_IMG = 1 << 13
} VkFormatFeatureFlagBits;

typedef enum {
    VK_SHARING_MODE_EXCLUSIVE = 0,
    VK_SHARING_MODE_CONCURRENT = 1
} VkSharingMode;

typedef enum {
    VK_PHYSICAL_DEVICE_TYPE_OTHER = 0,
    VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU = 1,
    VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU = 2,
    VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU = 3,
    VK_PHYSICAL_DEVICE_TYPE_CPU = 4
} VkPhysicalDeviceType;

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
    VK_SUBOPTIMAL_KHR = 1000001003,
    VK_ERROR_OUT_OF_DATE_KHR = -1000001004,
    VK_ERROR_INVALID_EXTERNAL_HANDLE_KHR = -1000072003
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
    VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV = 1000026000,
    VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV = 1000026001,
    VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV = 1000026002,
    VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR = 1000001000,
    VK_STRUCTURE_TYPE_PRESENT_INFO_KHR = 1000001001,
    VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR = 1000060007,
    VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR = 1000060008,
    VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR = 1000060009,
    VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR = 1000060010,
    VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR = 1000060011,
    VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR = 1000060012,
    VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO_KHR = 1000072000,
    VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_KHR = 1000072001,
    VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_KHR = 1000072002,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR = 1000059000,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR = 1000059001,
    VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2_KHR = 1000059002,
    VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2_KHR = 1000059003,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2_KHR = 1000059004,
    VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2_KHR = 1000059005,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2_KHR = 1000059006,
    VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2_KHR = 1000059007,
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2_KHR = 1000059008
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
    VK_SAMPLER_ADDRESS_MODE_REPEAT = 0,
    VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT = 1,
    VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE = 2,
    VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER = 3,
    VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE = 4
} VkSamplerAddressMode;

typedef enum {
    VK_FILTER_NEAREST = 0,
    VK_FILTER_LINEAR = 1,
    VK_FILTER_CUBIC_IMG = 1000015000
} VkFilter;

typedef enum {
    VK_SAMPLER_MIPMAP_MODE_NEAREST = 0,
    VK_SAMPLER_MIPMAP_MODE_LINEAR = 1
} VkSamplerMipmapMode;

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
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT = 1 << 0,
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT = 1 << 1,
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT = 1 << 2,
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT = 1 << 3,
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_KMT_BIT = 1 << 4,
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP_BIT = 1 << 5,
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE_BIT = 1 << 6
} VkExternalMemoryHandleTypeFlagBits;
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

typedef struct VkAllocationCallbacks {
    void*           pUserData;
    PFN_vkAllocationFunction   pfnAllocation;
    PFN_vkReallocationFunction pfnReallocation;
    PFN_vkFreeFunction    pfnFree;
    PFN_vkInternalAllocationNotification pfnInternalAllocation;
    PFN_vkInternalFreeNotification pfnInternalFree;
} VkAllocationCallbacks;

typedef struct VkFormatProperties {
    VkFormatFeatureFlags   linearTilingFeatures;
    VkFormatFeatureFlags   optimalTilingFeatures;
    VkFormatFeatureFlags   bufferFeatures;
} VkFormatProperties;

typedef struct VkBufferCreateInfo {
    VkStructureType sType;
    const void*            pNext;
    VkBufferCreateFlags    flags;
    VkDeviceSize           size;
    VkBufferUsageFlags     usage;
    VkSharingMode          sharingMode;
    uint32_t               queueFamilyIndexCount;
    const uint32_t*        pQueueFamilyIndices;
} VkBufferCreateInfo;

typedef struct VkBufferViewCreateInfo {
    VkStructureType sType;
    const void*            pNext;
    VkBufferViewCreateFlags flags;
    VkBuffer               buffer;
    VkFormat               format;
    VkDeviceSize           offset;
    VkDeviceSize           range;
} VkBufferViewCreateInfo;

typedef struct VkSamplerCreateInfo {
    VkStructureType sType;
    const void*            pNext;
    VkSamplerCreateFlags   flags;
    VkFilter               magFilter;
    VkFilter               minFilter;
    VkSamplerMipmapMode    mipmapMode;
    VkSamplerAddressMode   addressModeU;
    VkSamplerAddressMode   addressModeV;
    VkSamplerAddressMode   addressModeW;
    float                  mipLodBias;
    VkBool32               anisotropyEnable;
    float                  maxAnisotropy;
    VkBool32               compareEnable;
    VkCompareOp            compareOp;
    float                  minLod;
    float                  maxLod;
    VkBorderColor          borderColor;
    VkBool32               unnormalizedCoordinates;
} VkSamplerCreateInfo;

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

typedef struct VkDedicatedAllocationBufferCreateInfoNV {
    VkStructureType sType;
    const void*                      pNext;
    VkBool32                         dedicatedAllocation;
} VkDedicatedAllocationBufferCreateInfoNV;

typedef struct VkPhysicalDeviceProperties2 {
    VkStructureType sType;
    void*                            pNext;
    VkPhysicalDeviceProperties       properties;
} VkPhysicalDeviceProperties2;

typedef VkPhysicalDeviceProperties2 VkPhysicalDeviceProperties2KHR;

typedef struct VkExternalMemoryBufferCreateInfo {
    VkStructureType sType;
    const void*                      pNext;
    VkExternalMemoryHandleTypeFlags handleTypes;
} VkExternalMemoryBufferCreateInfo;

typedef VkExternalMemoryBufferCreateInfo VkExternalMemoryBufferCreateInfoKHR;

PFN_vkVoidFunction vkGetInstanceProcAddr(VkInstance, const char*);

/* Per-instance function pointers */
struct FlextVkInstance {
    void    (*GetPhysicalDeviceProperties2KHR)(VkPhysicalDevice, VkPhysicalDeviceProperties2*);
    PFN_vkVoidFunction    (*GetDeviceProcAddr)(VkDevice, const char*);
    void    (*GetPhysicalDeviceFormatProperties)(VkPhysicalDevice, VkFormat, VkFormatProperties*);
    void    (*GetPhysicalDeviceProperties)(VkPhysicalDevice, VkPhysicalDeviceProperties*);
};

/* Per-instance function pointer initialization */
void flextVkInitInstance(VkInstance instance, FlextVkInstance* data);

/* Per-device function pointers */
struct FlextVkDevice {
    void    (*CmdDrawIndexed)(VkCommandBuffer, uint32_t, uint32_t, uint32_t, int32_t, uint32_t);
    VkResult    (*CreateBuffer)(VkDevice, const VkBufferCreateInfo*, const VkAllocationCallbacks*, VkBuffer*);
    VkResult    (*CreateBufferView)(VkDevice, const VkBufferViewCreateInfo*, const VkAllocationCallbacks*, VkBufferView*);
    VkResult    (*CreateSampler)(VkDevice, const VkSamplerCreateInfo*, const VkAllocationCallbacks*, VkSampler*);
};

void flextVkInitInstance(VkInstance instance, FlextVkInstance* data) {
    data->GetPhysicalDeviceProperties2KHR = reinterpret_cast<void(*)(VkPhysicalDevice, VkPhysicalDeviceProperties2*)>(vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceProperties2KHR"));
    data->GetDeviceProcAddr = reinterpret_cast<PFN_vkVoidFunction(*)(VkDevice, const char*)>(vkGetInstanceProcAddr(instance, "vkGetDeviceProcAddr"));
    data->GetPhysicalDeviceFormatProperties = reinterpret_cast<void(*)(VkPhysicalDevice, VkFormat, VkFormatProperties*)>(vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceFormatProperties"));
    data->GetPhysicalDeviceProperties = reinterpret_cast<void(*)(VkPhysicalDevice, VkPhysicalDeviceProperties*)>(vkGetInstanceProcAddr(instance, "vkGetPhysicalDeviceProperties"));
}

void flextVkInitDevice(VkDevice device, FlextVkDevice* data, PFN_vkVoidFunction( *getDeviceProcAddr)(VkDevice, const char*)) {
    data->CmdDrawIndexed = reinterpret_cast<void(*)(VkCommandBuffer, uint32_t, uint32_t, uint32_t, int32_t, uint32_t)>(getDeviceProcAddr(device, "vkCmdDrawIndexed"));
    data->CreateBuffer = reinterpret_cast<VkResult(*)(VkDevice, const VkBufferCreateInfo*, const VkAllocationCallbacks*, VkBuffer*)>(getDeviceProcAddr(device, "vkCreateBuffer"));
    data->CreateBufferView = reinterpret_cast<VkResult(*)(VkDevice, const VkBufferViewCreateInfo*, const VkAllocationCallbacks*, VkBufferView*)>(getDeviceProcAddr(device, "vkCreateBufferView"));
    data->CreateSampler = reinterpret_cast<VkResult(*)(VkDevice, const VkSamplerCreateInfo*, const VkAllocationCallbacks*, VkSampler*)>(getDeviceProcAddr(device, "vkCreateSampler"));
}
