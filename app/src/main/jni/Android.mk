LOCAL_PATH := $(call my-dir)  //构建系统提供的宏函数 my-dir 将返回当前目录（Android.mk 文件本身所在的目录）的路径。
include $(CLEAR_VARS)
LOCAL_MODULE := hello-jni  //每个模块名称必须唯一，且不含任何空格。构建系统在生成最终共享库文件时，会对您分配给 LOCAL_MODULE 的名称自动添加正确的前缀和后缀。例如，上述示例会生成名为 libhello-jni.so 的库。
LOCAL_SRC_FILES := hello-jni.c
include $(BUILD_SHARED_LIBRARY)