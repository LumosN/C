#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>
char *strcat(char *dest, const char *src)
{
	assert(dest != NULL);
	assert(src != NULL);
	char* ret = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char s1[10] = "abcd";
	char s2[] = "ef";
	printf("%s", strcat(s1, s2));
	return 0;
}