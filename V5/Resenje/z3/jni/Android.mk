LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE:= libfibonacci
LOCAL_MODULE_TAGS:= optional
LOCAL_SRC_FILES:= fibonacci.c
LOCAL_SHARED_LIBRARIES += liblog libutils libcutils
LOCAL_CPPFLAGS:= -O0 -fno-inline

include $(BUILD_SHARED_LIBRARY)
