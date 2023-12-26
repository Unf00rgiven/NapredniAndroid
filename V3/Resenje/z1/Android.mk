LOCAL_PATH:=$(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= hellolog.c
LOCAL_MODULE:= hellolog
LOCAL_SHARED_LIBRARIES += liblog libutils libcutils
LOCAL_MODULE_TAGS:= optional

include $(BUILD_EXECUTABLE)
