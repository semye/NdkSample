#include <jni.h>
#include <string>
#include "semye.h"
#include "android/log.h"

using namespace std;

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_ndksample_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    string hello = "Hello from C++ by yesheng";
    return env->NewStringUTF(hello.c_str());
}

string jstring2str(JNIEnv *env, jstring jstr) {
    char *rtn = NULL;
    jclass clsstring = env->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("GB2312");
    jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray) env->CallObjectMethod(jstr, mid, strencode);
    jsize alen = env->GetArrayLength(barr);
    jbyte *ba = env->GetByteArrayElements(barr, JNI_FALSE);
    if (alen > 0) {
        rtn = (char *) malloc(alen + 1);
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    env->ReleaseByteArrayElements(barr, ba, 0);
    std::string stemp(rtn);
    free(rtn);
    return stemp;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_ndksample_MainActivity_printLog(JNIEnv *env, jobject thiz, jstring tag) {
    __android_log_print(ANDROID_LOG_DEBUG, "MainActivity", "%s==%s", SEMYE,
                        jstring2str(env, tag).c_str());
}

