// Copyright 2023-2024, The Khronos Group Inc.
//
// Based in part on code that is:
//
// Copyright (C) Microsoft Corporation.  All Rights Reserved
// Licensed under the MIT License. See License.txt in the project root for license information.
//
// SPDX-License-Identifier: MIT AND Apache-2.0

#pragma once

#include "VkCommon.h"
#include "VkResources.h"

#include "../PbrCommon.h"

#include "utilities/vulkan_scoped_handle.h"

#include <openxr/openxr.h>
#include <vulkan/vulkan_core.h>

#include <stdint.h>
#include <vector>

namespace Pbr
{
    struct VulkanResources;

    namespace VulkanTexture
    {
        VulkanTextureBundle LoadTextureImage(VulkanResources& pbrResources, bool sRGB, const uint8_t* fileData, uint32_t fileSize);

        VulkanTextureBundle CreateFlatCubeTexture(VulkanResources& pbrResources, RGBAColor color, bool sRGB);

        VulkanTextureBundle CreateTexture(VulkanResources& pbrResources, const Conformance::Image::Image& image);

        VkSamplerCreateInfo DefaultSamplerCreateInfo();
        VkSampler CreateSampler(VkDevice device, VkSamplerAddressMode addressMode = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE);
    }  // namespace VulkanTexture
}  // namespace Pbr
