#ifndef ANDROID_IEXAMPLE_H
#define ANDROID_IEXAMPLE_H

#include <binder/IInterface.h>

namespace android
{

class IExample : public IInterface
{
public:

    enum 
    {
        EXEC = IBinder::FIRST_CALL_TRANSACTION,
    };

	virtual int exec(String16&) = 0;

    DECLARE_META_INTERFACE(Example);
};

}

#endif
