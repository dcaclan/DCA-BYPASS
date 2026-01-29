LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE    := dca_logic
LOCAL_SRC_FILES := dca_logic.cpp
LOCAL_LDFLAGS   := -llog -ldl
include $(BUILD_EXECUTABLE)
