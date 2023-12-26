#include <stdio.h>
#include <cutils/log.h>
#include "gdbexample_lib_1.h"

int main()
{

	int res1 = lib1_func1(10, 15, 25, 30);
	int res2 = lib1_func2(10, 15, 25, 30);
	int res3 = lib1_func3(10, 15, 25, 30);
	int res4 = lib1_func4(10, 15, 25, 30);

	printf("res1 = %d\nres2 = %d\nres3 = %d\nres4 = %d\n", res1, res2, res3, res4);
	
	return res1 + res2 + res3 + res4;
}
