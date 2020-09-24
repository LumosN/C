#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
char* my_strcpy(char* dest, const char* src)
{
	char* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest++ = *src++)//'\0'的ASCll码值是0
	{
		;
	}
	return dest;
}
int main()
{
	char arr1[20] = { 0 };
	char arr2[20] = { 0 };
	printf("输入字符串\n");
	scanf("%s", &arr1);
	printf("%s", my_strcpy(arr2, arr1));//把arr1中的字符串copy到arr2中  
	return 0;
}
