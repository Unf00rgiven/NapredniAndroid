#include "gdbexample_lib_2.h"
#include "gdbexample_lib_3.h"

int lib2_func1(int value1, int value2, int value3, int value4)
{
	int tmp1 = 0, tmp2 = 0, tmp3 = 0;
	tmp1 = value1 * value2 + value1 * value2;
	tmp2 = value3 * value4 + value3 * value4;
	tmp3 = lib3_func1(value1, value2, value3, value4);
	return tmp1 * tmp2 * tmp3;
}

int lib2_func2(int value1, int value2, int value3, int value4)
{
	int tmp1 = 0, tmp2 = 0, tmp3 = 0;
	int *value1_ptr = (int *)value1;
	tmp1 = value1 + value2 + *value1_ptr;
	tmp2 = value3 + value4;
	tmp3 = lib3_func2(value1, value2, value3, value4);
	return tmp1 + tmp2 + tmp3;
}

int lib2_func3(int value1, int value2, int value3, int value4)
{
	float tmp1 = 0.0f, tmp2 = 0.0f;
	for (int i = 0; i < value3; i++){
		tmp1 += value1*(value2--)*(value4--);
	}
	tmp2 = lib3_func3(value1, value2, value3, value4);
	return (int)tmp1 + (int)tmp2;
}

int lib2_func4(int value1, int value2, int value3, int value4)
{
	float tmp1 = 0.0f, tmp2 = 0.0f;
	for (int i = 0; i < value2; i++){
		tmp1 += value2/(value3--);
	}
	tmp2 = lib3_func4(value1, value2, value3, value4);
	return (int)tmp1 + (int)tmp2;
}
