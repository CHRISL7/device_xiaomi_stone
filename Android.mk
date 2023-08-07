LOCAL_PATH := $(call my-dir)

ifeq ($(TARGET_DEVICE),stone)
include $(call all-makefiles-under,$(LOCAL_PATH))

# Kernel headers
$(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr: $(wildcard device/xiaomi/stone-kernel/kernel-headers/*)
	rm -rf $@
	mkdir -p $@/include
	cp -a device/xiaomi/stone-kernel/kernel-headers/. $@/include

endif
