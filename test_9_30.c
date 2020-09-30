#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);
	total += money;//买的汽水
	empty = money;//喝的汽水
	while (empty >= 2)
	{
		total += empty / 2;//换回来的汽水，喝掉了
		empty = empty / 2 + empty % 2;//盘点手里的空瓶
	}
	printf("共能喝到%d瓶汽水\n", total);//total=2*money-1


	return 0;
}