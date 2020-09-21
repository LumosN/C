#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int mystrlen(char* str)
{
	char* start = str;
	while (*str != '\0')
	{
		str++;
	}
	return (str - start);
}
int main()
{
	char arr[20] = { 0 };
	scanf("%s", &arr);
	printf("%d", mystrlen(arr));
	return 0;
}