#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<limits.h>
//模拟实现atoi 把字符串变成整数 a - int
enum State
{
	VALID,
	INVALID
}state = INVALID;
int my_atoi(const char* str)
{
	int flag = 1;
	long long ret = 0;
	if (str == NULL)
	{
		return 0;
	}
	while (isspace(*str))
	{
		str++;
	}
	if (*str == '+')
	{
		flag = 1;
		str++;
	}
	else if (*str == '-')
	{
		flag = -1;
		str++;
	}
	while (isdigit(*str))
	{
		ret = ret * 10 + flag*(*str - '0');
		if (ret > INT_MAX || ret < INT_MIN)
		{
			ret = 0;
			return (int)ret;
		}
		str++;
	}
	if (*str == '\0')
	{
		state = VALID;
		return (int)ret;
	}
	return (int)ret;
}
int main()
{
	char *arr= "   -123";
	int ret = my_atoi(arr);
	if (state == VALID)
	{
		printf("%d", ret);
	}
	else
	{
		printf("非法：%d", ret);
	}
	return 0;
}