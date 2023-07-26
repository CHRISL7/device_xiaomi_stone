#
# Copyright (C) 2023 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

LOCAL_PATH := $(call my-dir)

ifeq ($(TARGET_DEVICE),moonstone)
include $(call all-makefiles-under,$(LOCAL_PATH))

# Kernel headers
$(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr: $(wildcard device/xiaomi/moonstone-kernel/kernel-headers/*)
	rm -rf $@
	mkdir -p $@/include
	cp -a device/xiaomi/moonstone-kernel/kernel-headers/. $@/include

endif
