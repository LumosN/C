#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
void reverse(char* left, char* right)
{
	while (left < right)
	{
		char temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}
void reverse_string(char* str)
{
	char* left = str;
	char* right = str + strlen(str) - 1;
	while (*str != '\0')
	{
		char* begin = str;
		char* end = str;
		while (*end != '\0'&&*end != ' ')
		{
			end++;
		}
		//倒置一个单词
		reverse(begin, end - 1);
		if (*end != '\0')
		{
			str = end + 1;
		}
		else str = end;  //才可以跳出循环呀。
	}
	//倒置整个字符串
	reverse(left, right);
}
int main()
{
	char ch[100] = { 0 };
	gets(ch);
	reverse_string(ch);
	printf("%s", ch);
	return 0;
}
