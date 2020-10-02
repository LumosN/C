#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int numJewelsInStones(char * J, char * S)
{
	int i = 0, j = 0, count = 0;
	for (i = 0; i<strlen(J); i++)//从宝石中查找
	{
		for (j = 0; j<strlen(S); j++)//与每一块石头进行比较，看哪一个是宝石
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
	printf("分别输入宝石和石头\n");
	scanf("%s %s", &J,&S);
	printf("%d\n",numJewelsInStones(J, S));
	return 0;
}