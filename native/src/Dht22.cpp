#include <jni.h>
#include "onextent_iot_dht22_Dht22.h"
#include <ctype.h>
#include <string.h>

JNIEXPORT jfloatArray JNICALL Java_onextent_iot_dht22_Dht22_get
(JNIEnv * env, jobject obj) {

    float arr[3]={25.1,75.2,48.3};
    jfloatArray ret = env->NewFloatArray(3);

    env->SetFloatArrayRegion(ret,0,3,arr);

    return ret;
}

