#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 6 };//找出 5和6
	int ret = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		ret ^= arr[i];
	}
	//ret肯定不为0，我们要找出ret哪一位不为0
	//计算ret的哪一位为1
	for (i = 0; i < 32; i++)
	{
		if (((ret >> i) & 1) == 1)//找到了第i位 为1
		{
			break;
		}
	}
	//遍历上面数组，看数组中的元素，哪一个数字的第i位为1，哪一个数字的第i位为0
	int j = 0;
	int num1 = 0, num2 = 0;
	for (j = 0; j < sz; j++)
	{
		//分组 11335 22446 这样异或在一起 得到的就是5 或 6
		//而实际上，把整个数组都异或在一起，得到的ret是5^6
		if ((arr[j] >> i) & 1 == 1)
		{
			num1 ^= arr[j];
		}
		//if ((arr[j] >> i) & 1 == 0)
		//{
		//	num2 ^= arr[j];
		//}
	}
	num2 = ret^num1;
	printf("%d %d", num1, num2);
	return 0;
}