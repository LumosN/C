#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);
	total += money;//�����ˮ
	empty = money;//�ȵ���ˮ
	while (empty >= 2)
	{
		total += empty / 2;//����������ˮ���ȵ���
		empty = empty / 2 + empty % 2;//�̵�����Ŀ�ƿ
	}
	printf("���ܺȵ�%dƿ��ˮ\n", total);//total=2*money-1


	return 0;
}