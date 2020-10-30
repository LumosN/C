#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
void* my_memcpy1(void* dest, const void *src, size_t count)
{
	assert(dest);
	assert(src);
	void* ret = dest;
	int i = 0;
	for (i = 0; i < count; i++)
	{
		*((char*)dest + i) = *((char*)src + i);
	}
	return ret;
}
void* my_memcpy2(void* dest, const void *src, size_t count)
{
	assert(dest);
	assert(src);
	void* ret = dest;
	while (count--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
}
