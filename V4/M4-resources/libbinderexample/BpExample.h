#include "IExample.h"

namespace android
{

class BpExample : public BpInterface<IExample>
{

public:

    BpExample(const sp<IBinder>& impl);

    virtual int32_t getExample();

};

}
