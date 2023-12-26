#define LOG_NDEBUG 0
#define LOG_TAG "BnExample"

#include <cutils/log.h>
#include <binder/Parcel.h>

#include "BnExample.h"

using namespace android;

status_t BnExample::onTransact(uint32_t code, const Parcel& data,
        Parcel* reply, uint32_t flags __attribute__((unused)))
{
    ALOGV("%s enter: code = %d", __FUNCTION__, code);

    data.checkInterface(this);
    
    switch(code)
    {
        
        case GET_EXAMPLE:
        {
            int32_t example = getExample();

            reply->writeNoException();
            reply->writeInt32(example);

            break;
        }
    }

    ALOGV("%s exit", __FUNCTION__);
    return NO_ERROR;
}
