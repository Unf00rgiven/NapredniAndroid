#include <jni.h>
#include <unistd.h>
#include <math.h>

#define LOG_TAG "fibonacci"
#include <cutils/log.h>

jint Java_rtrk_pnrs_jniexample_FibonacciNative_get(JNIEnv *env, jobject this, jint num) {
	double golden_ration = 1.6180339887;
	double sqrt_5 = 2.236067977;
	int ret_val, power_val;
	
	ALOGD("JNI fibonacci called parameter %d", num);
	power_val = pow(golden_ration, num);
	power_val = power_val/sqrt_5 + 0.5;
	ret_val = floor(power_val);
	ALOGD("JNI fibonacci return value %d", ret_val);
	return ret_val;
}
