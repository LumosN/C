#include<stdio.h>
int func1(int n)//µÝ¹é 
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	if (n > 2)
	{
		return func1(n - 1) + func1(n - 2);
	}
}
int func2(int n)//·ÇµÝ¹é 
{
	int a = 1, b = 1, c = 1;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("µÝ¹é n = %d\n", func1(n));
	printf("µÝ¹é n = %d", func2(n));
	return 0;
}
