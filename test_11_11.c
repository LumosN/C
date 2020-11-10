#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h> 
int main()
{
	int i = 0, j = 0;
	int n;
	int arr[1000];
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
		for (j = 1; j < i; j++)
		{
			if (arr[i] == arr[j])
			{
				i--;
				n--;
			}
		}
	}
	for (i = 1; i <= n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
