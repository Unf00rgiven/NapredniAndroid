#include <binder/IBinder.h>
#include <cutils/properties.h>
#include <binder/IServiceManager.h>
#include <cutils/log.h>
#include <unistd.h>
#include <IExample.h>
#include <string.h>
#include <cutils/ashmem.h>
#include <sys/mman.h>

#define ASHMEM_BUFFER_SIZE (100U)

#define LOG_TAG "ASHMEM_TEST"

using namespace android;

int main(int argc, char** argv) {
	sp<IServiceManager> smanager = defaultServiceManager();
    if (smanager == NULL) {
        ALOGE("Failed to obtain IServiceManager");
        return 1;
    }

    sp<IBinder> binder = smanager->getService(String16("Example"));
    if (binder == NULL) {
        ALOGE("Failed to obtain Example service");
        return 1;
    }

	sp<IExample> example = interface_cast<IExample>(binder);
    if (example == NULL) {
        ALOGE("Failed to obtain IExample interface");
        return 1;
    }

    int testValue = example->getExample();
    ALOGD("Ashmem region file descriptor: %d", testValue);

	 void *ptr = mmap(NULL, ASHMEM_BUFFER_SIZE * sizeof(char), PROT_READ, MAP_SHARED, testValue, 0);
    if (ptr == MAP_FAILED) {
        ALOGE("Failed to map ashmem memory");
        return 1;
    }

    ALOGD("Ashmem memory value: 0x%x", *((int*)ptr));

    // Cleanup
    munmap(ptr, ASHMEM_BUFFER_SIZE);
    close(testValue);
    return 0;
}
