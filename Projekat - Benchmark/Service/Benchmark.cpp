#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>

#include <cutils/log.h>
#include <unistd.h>
#include <stdlib.h>

#include <utils/String16.h>

#include "Benchmark.h"

#define LOG_TAG "BENCHMARK"

using namespace android;

Benchmark::Benchmark(){
	ALOGD("Constructor called");
}

Benchmark::~Benchmark(){
    ALOGD("Destructor called!");
}

int Benchmark::exec(String16& command) {
	ALOGD("Exec method called");
	const char* str = String8(command).string();
	ALOGD("str : %s", str);
	int res = system(str);
	ALOGD("res : %d", res);
	return res;
}

int main(){
	ALOGD("BENCHMARK SERVICE STARTED");
	defaultServiceManager()->addService(String16("benchmark"), new Benchmark());
	android::ProcessState::self()->startThreadPool();
	IPCThreadState::self()->joinThreadPool();

	return 0;
}
