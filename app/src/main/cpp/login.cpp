#include <jni.h>
#include <string>
#include <string.h>

extern "C"
JNIEXPORT jstring
JNICALL
Java_com_example_wushufeng_ndk_1demo_LoginActivity_login(JNIEnv *env, jobject instance,
                                                         jstring name_, jstring password_,
                                                         jint authcode) {
    jclass jclazz = env -> FindClass("com/example/wushufeng/ndk_demo/LoginActivity");
    jfieldID nameError = env->GetFieldID(jclazz,"strNameNotExist","Ljava/lang/String;");
    jfieldID passwordError = env->GetFieldID(jclazz,"strPasswordError","Ljava/lang/String;");
    jfieldID loginSuccess = env->GetFieldID(jclazz,"strLoginSuccess","Ljava/lang/String;");

    jstring strNameNotExist = (jstring)env->GetObjectField(instance,nameError);
    jstring strPasswordError = (jstring)env->GetObjectField(instance,passwordError);
    jstring strLoginSuccess = (jstring)env->GetObjectField(instance,loginSuccess);
    jstring result;
    if(authcode==888){
        const char *name = env->GetStringUTFChars(name_, 0);
        const char *password = env->GetStringUTFChars(password_, 0);
        if(strcmp(name,"wushufeng")!=0){
            return strNameNotExist;
        }else{
            if(strcmp(password,"123456")!=0){
                return strPasswordError;
            }else{
                return strLoginSuccess;
            }
        }
    }
}
