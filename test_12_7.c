#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//œ‡ºı
int missingNumber1(int* nums, int numsSize)
{
	int i = 0, sum1 = 0, sum2 = 0;
	for (i = 0; i<numsSize; i++)
	{
		sum1 += nums[i];
	}
	for (i = 0; i<numsSize + 1; i++)
	{
		sum2 += i;
	}
	return sum2 - sum1;
}
//“ÏªÚ
int missingNumber2(int* nums, int numsSize)
{
	int i = 0, num = 0;
	for (i = 0; i<numsSize; i++)
	{
		num ^= nums[i];
	}
	for (i = 0; i<numsSize + 1; i++)
	{
		num ^= i;
	}
	return num;
}