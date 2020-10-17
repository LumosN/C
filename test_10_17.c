#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int left_revolve(char s1[], int n)
{
	int i = 0;
	char* p = s1;
	for (i = 0; i < n ; i++)
	{
		s1 = p;
		char temp = s1[0];
		while (*(s1 + 1) != '\0')//Ò»´Î×óÐý
		{
			*(s1) = *(s1 + 1);
			s1++;
		}
		*s1 = temp;
	}
	return 0;
}
int right_revolve(char s1[], int n,int sz)
{
	int i = 0, j = 0;
	for (i = 0; i < n; i++)
	{
		char p = s1[sz - 1];
		for (j = sz - 1; j >= 0; j--)
		{
			s1[j] = s1[j - 1];
		}
		s1[0] = p;
	}
}
int main()
{
	char s1[] = "AABCD";
	left_revolve(s1, 1);
	right_revolve(s1, 1, 5);
	printf("%s", s1);
	return 0;
}