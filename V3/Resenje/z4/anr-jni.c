#include <jni.h>
#include <unistd.h>

static unsigned int z = 0;

void
Java_rtrk_pnrs_anr_ANRExample_anrSleep( JNIEnv* env, jobject thiz )
{
    sleep(20);
}

unsigned
Java_rtrk_pnrs_anr_ANRExample_anrCrash( JNIEnv* env, jobject thiz )
{
    unsigned* x = &z;
    *x = 10;
    return *x;
}
