// Copyright (C) 2023 Intel Corporation
// Part of the Unified-Runtime Project, under the Apache License v2.0 with LLVM Exceptions.
// See LICENSE.TXT
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include "fixtures.hpp"

TEST(valTest, urInit) {
    const ur_device_init_flags_t device_flags =
        UR_DEVICE_INIT_FLAG_FORCE_UINT32;
    ASSERT_EQ(UR_RESULT_ERROR_INVALID_ENUMERATION, urInit(device_flags));
}

TEST_F(valPlatformsTest, testUrPlatformGetApiVersion) {
    ur_api_version_t api_version = {};

    ASSERT_EQ(urPlatformGetApiVersion(nullptr, &api_version),
              UR_RESULT_ERROR_INVALID_NULL_HANDLE);

    for (auto p : platforms) {
        ASSERT_EQ(urPlatformGetApiVersion(p, nullptr),
                  UR_RESULT_ERROR_INVALID_NULL_POINTER);
    }
}
