#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
void* my_memmove(void *dest, const void *src, size_t count)
{
	assert(dest);
	assert(src);
	if (dest < src)
	{
		//��ǰ���
		while (count--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		while (count--)
		{
			//�Ӻ���ǰ
			*((char*)dest + count) = *((char*)src + count);
		}
	}
}