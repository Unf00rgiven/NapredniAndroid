LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= hello_world.c
LOCAL_MODULE:= helloworld
LOCAL_MODULE_TAGS:= optional

include $(BUILD_EXECUTABLE)
