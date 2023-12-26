#define LOG_NDEBUG 0
#define LOG_TAG "BpExample"

#include <cutils/log.h>
#include <binder/Parcel.h>

#include "BpExample.h"

using namespace android;


BpExample::BpExample(const sp<IBinder>& impl) :
	BpInterface<IExample>(impl)
{

}

int BpExample::exec(String16& command)
{
    Parcel data, reply;
    int res;

    ALOGV("%s enter", __FUNCTION__);

    data.writeInterfaceToken(IExample::getInterfaceDescriptor());

	data.writeString16(command);
    
    remote()->transact(EXEC, data, &reply);

    reply.readInt32();
    reply.readInt32(&res);    

    ALOGV("%s exit", __FUNCTION__);
    return res;
}

