#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int numJewelsInStones(char * J, char * S)
{
	int i = 0, j = 0, count = 0;
	for (i = 0; i<strlen(J); i++)//�ӱ�ʯ�в���
	{
		for (j = 0; j<strlen(S); j++)//��ÿһ��ʯͷ���бȽϣ�����һ���Ǳ�ʯ
		{
			if (J[i] == S[j])
			{
				count++;
			}
		}
	}
	return count;
}
int main()
{
	char J[20] = "";
	char S[20] = "";
	printf("�ֱ����뱦ʯ��ʯͷ\n");
	scanf("%s %s", &J,&S);
	printf("%d\n",numJewelsInStones(J, S));
	return 0;
}