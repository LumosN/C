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
	printf("���Լ��%d", b);
	return 0;
}