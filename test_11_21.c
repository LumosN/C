#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#define MAX 20
//将字符串中的空格替换成%20
void replace(char* str, int length)
{
	int i = 0, count = 0;
	//数空格
	for (i = 0; i < length; i++)
	{
		if (str[i] == ' ')
		{
			count++;
		}
	}
	//从后向前检查并replace空格
	int newlen = length + 2 * count - 1;
	for (i = length-1; i >= 0; i--)
	{
		if (str[i] == ' ')
		{
			str[newlen--] = '0';
			str[newlen--] = '2';
			str[newlen--] = '%';
		}
		else
		{
			str[newlen--] = str[i];
		}
	}
}
int main()
{
	char str[MAX] = "hello world!";
	replace(str, strlen(str));
	printf("%s\n", str);
	return 0;
}