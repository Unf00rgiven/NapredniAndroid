LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= prop_example.c
LOCAL_MODULE:= prop_example
LOCAL_SHARED_LIBRARIES += liblog libutils libcutils
LOCAL_MODULE_TAGS:= optional

ifeq ($(TARGET_ARCH),x86)
LOCAL_FLAG:= -DDEBUG_X86
endif

include $(BUILD_EXECUTABLE)
