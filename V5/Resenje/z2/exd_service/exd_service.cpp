#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>

#define LOG_TAG "EXD_BINDER"

#include <cutils/ashmem.h>
#include <sys/mman.h>

#include <cutils/log.h>
#include <unistd.h>

#include "exd_service.h"

#define ASHMEM_BUFFER_SIZE (100U)

using namespace android;

Example::Example(){
	ALOGD("Constructor called");
	example_value = ashmem_create_region("Ashmem region name", ASHMEM_BUFFER_SIZE * sizeof(char));;
 
	ashmem_set_prot_region(example_value, PROT_READ | PROT_WRITE);

	ptr = mmap(NULL, ASHMEM_BUFFER_SIZE * sizeof(char),PROT_READ | PROT_WRITE, MAP_SHARED, example_value, 0);
	memset(ptr, 0x0, ASHMEM_BUFFER_SIZE * sizeof(char));
}

Example::~Example(){
	munmap(ptr, ASHMEM_BUFFER_SIZE);
    	ashmem_unpin_region(example_value, 0, 0);
	close(example_value);
}

int Example::getExample(){
	ALOGD("getExample called value is : %d", example_value);

	*((int *) ptr) = 0xCAFED00D;
	return example_value;
}

void Example::setExample(int value){
	ALOGD("setExample called");
	memcpy(ptr, &value, sizeof(int));
}

int main(){
	ALOGD("EXD SERVICE STARTED");
	defaultServiceManager()->addService(String16("Example"), new Example());
	android::ProcessState::self()->startThreadPool();
	IPCThreadState::self()->joinThreadPool();

	return 0;
}
