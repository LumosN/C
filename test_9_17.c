#include<stdio.h>
int count_one(int n)
{
	int count = 0;
	while (n)
	{
		n = n&(n - 1);
		count++;
	}
	return count;
}
int main()
{
	int a = 0;
	scanf("%d", &a);
	printf("%d",count_one(a));
	return 0;
}