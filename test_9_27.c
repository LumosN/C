#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main()
{
	int i = 0;
	int count = 0;
	int ret = 0;
	for (i = 0; i <= 100000; i++)
	{
		//判断i是否为自幂数
		//1.计算i的位数 2.获得i的每一位 3.计算每一位的位数的n次方和 4.比较并打印
		count = 1;
		ret = i;
		while (ret/=10)
		{
			count++;
		}
		int a = i / 1000, b = i % 1000 / 100, c = i % 100 / 10, d = i % 10;
		if ((pow(a, count) + pow(b, count) + pow(c, count) + pow(d, count)) == i)
		{
			printf("%d\n", i);
		}
	}
}
