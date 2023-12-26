LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= hello_world_shared.c
LOCAL_MODULE:= helloworld_shared
LOCAL_SHARED_LIBRARIES:= libhello
LOCAL_C_INCLUDES:= $(LOCAL_PATH)/../e1
LOCAL_MODULE_TAGS:= optional

include $(BUILD_EXECUTABLE)
