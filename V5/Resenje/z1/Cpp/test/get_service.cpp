#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <cutils/log.h>
#include <unistd.h>
#include <IExample.h>

#define LOG_TAG "TEST"

using namespace android;

int main(int argc, char** argv) {
	sp<IServiceManager> smanager = defaultServiceManager();
	sp<IBinder> binder = smanager->getService(String16("Example"));
	sp<IExample> example = interface_cast<IExample>(binder);
	int testValue = example -> getExample();
	ALOGD("Value : %d", testValue);
	testValue++;
	ALOGD("New value : %d", testValue);
	example->setExample(testValue);
	return 0;
}
