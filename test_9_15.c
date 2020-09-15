#include<stdio.h>
int FindArr(int x,int sz,int arr[])
{
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (x < arr[mid])
		{
			right = mid - 1;
		}
		else if (x>arr[mid])
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return 0;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int x = 0;
	int sz = sizeof(arr) / sizeof(arr[0]) - 1;
	printf("������Ҫ���ҵ�����\n");
	scanf("%d", &x);
	int ret = FindArr(x, sz, arr); 
	if (ret != 0)
	{
		printf("�ҵ���,�±�Ϊ��%d", ret);
	}
	else
	{
		printf("û�ҵ�");
	}
	return 0;
}