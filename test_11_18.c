#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 6 };//�ҳ� 5��6
	int ret = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		ret ^= arr[i];
	}
	//ret�϶���Ϊ0������Ҫ�ҳ�ret��һλ��Ϊ0
	//����ret����һλΪ1
	for (i = 0; i < 32; i++)
	{
		if (((ret >> i) & 1) == 1)//�ҵ��˵�iλ Ϊ1
		{
			break;
		}
	}
	//�����������飬�������е�Ԫ�أ���һ�����ֵĵ�iλΪ1����һ�����ֵĵ�iλΪ0
	int j = 0;
	int num1 = 0, num2 = 0;
	for (j = 0; j < sz; j++)
	{
		//���� 11335 22446 ���������һ�� �õ��ľ���5 �� 6
		//��ʵ���ϣ����������鶼�����һ�𣬵õ���ret��5^6
		if ((arr[j] >> i) & 1 == 1)
		{
			num1 ^= arr[j];
		}
		//if ((arr[j] >> i) & 1 == 0)
		//{
		//	num2 ^= arr[j];
		//}
	}
	num2 = ret^num1;
	printf("%d %d", num1, num2);
	return 0;
}