#include <jni.h>
#include <string>
#include <string.h>
#include <android/log.h>

#define LOG_TAG    "TAG_NDK"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

extern "C"
JNIEXPORT void
JNICALL
Java_com_example_wushufeng_ndk_1demo_LoginActivity_loginsuccess(JNIEnv *env, jobject instance,
                                                         jstring name_, jstring password_,
                                                         jint authcode) {
    jclass jclazz = env -> FindClass("com/example/wushufeng/ndk_demo/LoginActivity");
    jfieldID nameError = env->GetFieldID(jclazz,"strNameNotExist","Ljava/lang/String;");
    jfieldID passwordError = env->GetFieldID(jclazz,"strPasswordError","Ljava/lang/String;");
    jfieldID loginSuccess = env->GetFieldID(jclazz,"strLoginSuccess","Ljava/lang/String;");
    jmethodID showToastId = env -> GetMethodID(jclazz,"showToast","(Ljava/lang/String;)V");

    jstring strNameNotExist = (jstring)env->GetObjectField(instance,nameError);
    jstring strPasswordError = (jstring)env->GetObjectField(instance,passwordError);
    jstring strLoginSuccess = (jstring)env->GetObjectField(instance,loginSuccess);
    if(authcode==888){
        std::string hello = "888";
        const char *name = env->GetStringUTFChars(name_, 0);
        const char *password = env->GetStringUTFChars(password_, 0);
        if(strcmp(name,"wushufeng")!=0){
            env->CallVoidMethod(instance,showToastId,strNameNotExist);
            LOGD("%s\n", "用户名不存在！");
        }else{
            if(strcmp(password,"123456")!=0){
                env->CallVoidMethod(instance,showToastId,strPasswordError);
                LOGD("%s\n", "密码不正确！");
            }else{
                env->CallVoidMethod(instance,showToastId,strLoginSuccess);
                LOGD("%s\n", "登录成功！");
            }
        }
    }

}
