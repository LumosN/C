#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int sumPeach(int day)
{
	if (day == 10)
	{
		return 1;
	}
	else
	{
		return 2 * sumPeach(day + 1) + 2;
	}
}
int main()
{
	int sum = 0;
	sum = sumPeach(1);
	printf("the first day of picking peaches number is :%d\n", sum);
	return 0;
}