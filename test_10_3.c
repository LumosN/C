#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
char findTheDifference(char * s, char * t)
{
	int i = 0;
	int a = 0, b = 0;
	for (i = 0; i < strlen(t); i++)
	{
		b += t[i];
		if (i < strlen(t) - 1)
		{
			a += s[i];
		}
	}
	return (b - a);
}
int main()
{
	char ch1[20] = "abcd";
	char ch2[20] = "";
	scanf("%s", &ch2);
	printf("%c\n", findTheDifference(ch1, ch2));
	return 0;
}
