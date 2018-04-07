#include <jni.h>
#include <string>
#include <android/log.h>

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_example_wushufeng_ndk_1demo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    __android_log_print(ANDROID_LOG_DEBUG, "TAG_NDK", "File Name : %s\n", hello.c_str());
    return env->NewStringUTF(hello.c_str());
}