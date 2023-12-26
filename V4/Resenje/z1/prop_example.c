#define LOG_TAG "PROP_EXAMPLE"
#include <string.h>
#include <cutils/log.h>
#include <cutils/properties.h>

#define RTRK_PROPERTY		"rtrk.android"
#define RTRK_PROPERTY_VALUE	"RTRK"

int main() {
	int prop_len;
	char propRtrk[PROPERTY_VALUE_MAX];

	ALOGD("Property Native Example starting...\r\n");

	prop_len = property_get(RTRK_PROPERTY, propRtrk, "");
	if(prop_len > 0) {
		ALOGD("Read value for property rtrk.android \r\n");
		if (strncmp(propRtrk, RTRK_PROPERTY_VALUE, PROPERTY_VALUE_MAX) != 0) {
			property_set(RTRK_PROPERTY, RTRK_PROPERTY_VALUE);
			ALOGD("Properties are not equal, set propertie\r\n");
		}
	}
	else {
		property_set(RTRK_PROPERTY, RTRK_PROPERTY_VALUE);
		ALOGD("Propertie is NULL, set propertie\r\n");	
	}

	return 0;
}
