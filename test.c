#include<stdio.h>
void print_1(int x)
{
	int i;
	printf("奇数位：");
	for (i = 31; i > 0; i-=2)
	{
		printf("%d ", (x >> i) & 1);
	}
}
void print_2(int x)
{
	int i;
	printf("偶数位：");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (x >> i) & 1);
	}
}
int main()
{
	int x = 0;
	scanf("%d", &x);
	print_1(x);
	print_2(x);
	return 0;
}
