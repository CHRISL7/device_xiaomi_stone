#
# Copyright (C) 2023 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

DEVICE_PATH := device/xiaomi/moonstone

# Inherit from sm6375-common
include device/xiaomi/sm6375-common/BoardConfigCommon.mk

# Display
TARGET_SCREEN_DENSITY := 440

# OTA Assert
TARGET_OTA_ASSERT_DEVICE := moonstone

# Inherit from the proprietary version
include vendor/xiaomi/moonstone/BoardConfigVendor.mk
