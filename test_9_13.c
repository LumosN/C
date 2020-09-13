#include<stdio.h>
int main()
{
	int a, b;
	int c = 0;
	scanf("%d %d", &a, &b);
	while (c = a%b)
	{
		a = b;
		b = c;
	}
	printf("最大公约数%d", b);
	return 0;
}