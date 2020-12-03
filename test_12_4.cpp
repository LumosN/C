#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define NUM 2019
int check(int n)
{
	int is = 1;
	int a = n;
	while (a != 0)
	{
		if (a % 10 == 2 || a % 10 == 4)
		{
			is = 0;
			break;
		}
		a /= 10;
	}
	return is;
}
int main()
{
	int count = 0;
	for (int i = 1; i < NUM; i++)
	{
		for (int j = 1; j < NUM; j++)
		{
			for (int k = 1; k < NUM; k++)
			{
				if (i + j + k == NUM)
				{
					if (check(i) && check(j) && check(k))
					{
						if (i>j&&j>k)
						{
							count++;
						}
					}
				}
			}
		}
	}
	printf("%d", count);
	return 0;
}