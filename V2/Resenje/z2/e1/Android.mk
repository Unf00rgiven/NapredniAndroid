LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= libhello.c
LOCAL_MODULE:= libhello
LOCAL_MODULE_TAGS:= optional

include $(BUILD_STATIC_LIBRARY)
