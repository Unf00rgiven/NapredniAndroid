#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>

#define LOG_TAG "EXD_BINDER"
#include <cutils/log.h>
#include <unistd.h>

#include "exd_service.h"

using namespace android;

Example::Example(){
	ALOGD("Constructor called");
	example_value = 2;

	//fd = ashmem_create_region("Ashmem region name", ASHMEM_BUFFER_SIZE * sizeof(char));
	//ashmem_set_prot_region(fd, PROT_READ | PROT_WRITE);

	//void* ptr = mmap(NULL, ASHMEM_BUFFER_SIZE * sizeof(char),PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	//memset(ptr, 0x0, ASHMEM_BUFFER_SIZE * sizeof(char));
}

Example::~Example(){
	//munmap(ptr, ASHMEM_BUFFER_SIZE);
	//close(fd);
}

int Example::getExample(){
	ALOGD("getExample called");

	//*((int *) ptr) = 0xCAFED00D;
	return example_value;
}

void Example::setExample(int value){
	ALOGD("setExample called");
	example_value = value;
}

int main(){
	ALOGD("EXD SERVICE STARTED");
	defaultServiceManager()->addService(String16("Example"), new Example());
	android::ProcessState::self()->startThreadPool();
	IPCThreadState::self()->joinThreadPool();

	return 0;
}
