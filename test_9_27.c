#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main()
{
	int i = 0;
	int count = 0;
	int ret = 0;
	for (i = 0; i <= 100000; i++)
	{
		//�ж�i�Ƿ�Ϊ������
		//1.����i��λ�� 2.���i��ÿһλ 3.����ÿһλ��λ����n�η��� 4.�Ƚϲ���ӡ
		count = 1;
		ret = i;
		while (ret/=10)
		{
			count++;
		}
		int a = i / 1000, b = i % 1000 / 100, c = i % 100 / 10, d = i % 10;
		if ((pow(a, count) + pow(b, count) + pow(c, count) + pow(d, count)) == i)
		{
			printf("%d\n", i);
		}
	}
}
