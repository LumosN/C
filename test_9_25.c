#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int check_sys()
{
	int a = 1;
	char* p = (char*)&a;
	if (*p == 1)
	{
		return 1;
	}
	else return 0;
}
int main()
{
	if (check_sys()) printf("小端\n");
	else printf("大端\n");
	return 0;
}
