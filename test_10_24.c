#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int judge_revolve(char* s1, char* s2)
{
	if (strlen(s1) != strlen(s2))
	{
		printf("����\n");
		return 0;
	}
	int lenth = strlen(s1);
	strncat(s1, s1, lenth);//׷��s1��s1
	if (strstr(s1, s2) == NULL)
	{
		printf("����\n");
	}
	else
	{
		printf("��\n");
	}
}
int main()
{
	char s1[20] = "abcedf";
	char s2[] = "dfabce";
	judge_revolve(s1, s2);
	return 0;
}