#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
void my_strcpy(char* dest, const char* src)
{
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest++ = *src++)//'\0'��ASCll��ֵ��0
	{
		;
	}
}
int main()
{
	char arr1[20] = { 0 };
	char arr2[20] = { 0 };
	printf("�����ַ���\n");
	scanf("%s", arr1);
	my_strcpy(arr2, arr1);//��arr1�е��ַ���copy��arr2��
	printf("%s", arr2);
	return 0;
}