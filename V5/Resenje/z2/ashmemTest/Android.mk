LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:=ashmemTest.cpp
LOCAL_MODULE:=ashmemTest
LOCAL_SHARED_LIBRARIES += liblog libutils libcutils libbinderexample libbinder
LOCAL_MODULE_TAGS := optional
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../libbinderexample

ifeq ($(TARGET_ARCH),x86)
LOCAL_FLAG:= -DDEBUG_X86
endif

include $(BUILD_EXECUTABLE)
