#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
//判断一个数变成斐波那契数列中的数最少需要几步 
int main()
{
	int n, ret = 0;
	int f1 = 0, f2 = 1, f3 = 0;
	scanf("%d", &n);
	while (1)
	{
		if (n == f2)
		{
			ret = 0;
			break;
		}
		else if (n < f2)
		{
			if (abs(n - f1) > abs(n - f2))
			{
				ret = abs(n - f2);
				break;
			}
			else
			{
				ret = abs(n - f1);
				break;
			}
		}
		f3 = f2 + f1;
		f1 = f2;
		f2 = f3;
	}
	printf("%d\n", ret);

}