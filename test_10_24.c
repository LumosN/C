#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int judge_revolve(char* s1, char* s2)
{
	if (strlen(s1) != strlen(s2))
	{
		printf("不是\n");
		return 0;
	}
	int lenth = strlen(s1);
	strncat(s1, s1, lenth);//追加s1到s1
	if (strstr(s1, s2) == NULL)
	{
		printf("不是\n");
	}
	else
	{
		printf("是\n");
	}
}
int main()
{
	char s1[20] = "abcedf";
	char s2[] = "dfabce";
	judge_revolve(s1, s2);
	return 0;
}