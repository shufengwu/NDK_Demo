#include <jni.h>
#include <string>
#include <string.h>
#include <android/log.h>

#define LOG_TAG    "TAG_NDK_FILE"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

extern "C"
JNIEXPORT void JNICALL
Java_com_example_wushufeng_ndk_1demo_FileUtils_split(JNIEnv *env, jclass type, jstring path_,
                                                     jstring path_pattern_, jint count) {
    const char *path = env->GetStringUTFChars(path_, 0);
    const char *path_pattern = env->GetStringUTFChars(path_pattern_, 0);

    // TODO
    FILE* file = fopen(path, "rb");
    

    env->ReleaseStringUTFChars(path_, path);
    env->ReleaseStringUTFChars(path_pattern_, path_pattern);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_wushufeng_ndk_1demo_FileUtils_merge(JNIEnv *env, jclass type,
                                                     jstring path_pattern_, jint count,
                                                     jstring merge_path_) {
    const char *path_pattern = env->GetStringUTFChars(path_pattern_, 0);
    const char *merge_path = env->GetStringUTFChars(merge_path_, 0);

    // TODO

    env->ReleaseStringUTFChars(path_pattern_, path_pattern);
    env->ReleaseStringUTFChars(merge_path_, merge_path);
}