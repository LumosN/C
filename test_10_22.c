#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void _swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char temp = *(buf1 + i);
		*(buf1 + i) = *(buf2 + i);
		*(buf2 + i) = temp;
	}
}
void bubble_sort(void* base, int sz, int width, int(*cmp)(const void* e1, const void* e2))
{
	int i = 0, j = 0;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - i - 1; j++)
		{
			if (cmp((char*)base + j*width , (char*)base + (j + 1)*width)>0)
			{
				_swap((char*)base + j*width, (char*)base + (j + 1)*width, width);
			}
		}
	}
}
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
int cmp_char(const void* e1, const void* e2)
{
	return *(char*)e1 - *(char*)e2;
}
int main()
{
	int arr[] = { 8, 7, 6, 5, 4, 3, 2, 1 };
	char ch[] = "aecde";
	bubble_sort(arr, 8, 4, cmp_int);
	bubble_sort(ch, 5, 1, cmp_char);
	printf("%s", ch);
	printf("%d", arr[0]);
	return 0;
}