#include <stdio.h>

int main() {
#ifdef EXAMPLE_ANDROID 
	printf("EXAMPLE_ANDROID is defined\n");
#else
	printf("EXAMPLE_ANDROID is not defined\n");
#endif
	return 0;
}
