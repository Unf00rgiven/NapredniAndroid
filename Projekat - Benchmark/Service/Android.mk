LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := Benchmark.cpp
LOCAL_MODULE := benchmark
LOCAL_MODULE_TAGS := optional

LOCAL_SHARED_LIBRARIES += libutils
LOCAL_SHARED_LIBRARIES += libcutils
LOCAL_SHARED_LIBRARIES += libbinder
LOCAL_SHARED_LIBRARIES += libbinderexample

include $(BUILD_EXECUTABLE)
