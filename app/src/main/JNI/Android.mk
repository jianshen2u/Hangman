LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE:=ledcontrol
LOCAL_SRC_FILES:=ledcontrol.c
include $(BUILD_SHARED_LIBRARY)