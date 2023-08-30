// Copyright (C) 2022-2023 Intel Corporation
// Part of the Unified-Runtime Project, under the Apache License v2.0 with LLVM Exceptions.
// See LICENSE.TXT
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#include <uur/checks.h>

struct urTearDownTest : testing::Test {
    void SetUp() override {
        ur_device_init_flags_t device_flags = 0;
        ASSERT_SUCCESS(urInit(device_flags, nullptr));
    }
};

TEST_F(urTearDownTest, Success) {
    ur_tear_down_params_t tear_down_params{};
    ASSERT_SUCCESS(urTearDown(&tear_down_params));
}

TEST_F(urTearDownTest, InvalidNullPointerParams) {
    ASSERT_EQ_RESULT(UR_RESULT_ERROR_INVALID_NULL_POINTER, urTearDown(nullptr));
}
