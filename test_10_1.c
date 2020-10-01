#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int arr1[] = { 1, 2, 3 };//arr1 - int*
	int arr2[] = { 2, 3, 4 };//arr2 - int*
	int arr3[] = { 3, 4, 5 };//arr3 - int*

	int* arr[3] = { arr1, arr2, arr3 };//指针数组的使用

	int i = 0, j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d ", arr[i][j]);//arr[0]代表arr1的地址，以此类推
		}
		printf("\n");
	}
	return 0;
}