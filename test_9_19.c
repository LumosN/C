#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	int i = 0, j = 0, k = 0;
	for (i = 0; i < n / 2 + 1; i++)//上半部分
	{
		for (j = 0; j < 2 - i; j++)
		{
			printf(" ");
		}
		for (k = 0; k <= 2 * i; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 0; i < n / 2; i++)//下半部分
	{
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		for (k = 0; k <= (n/2)-2*i; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
