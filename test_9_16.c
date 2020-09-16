#include<stdio.h>
void  reverse_string(char arr[])
{
	char temp = arr[0];
	int len = strlen(arr);
	arr[0] = arr[len - 1];
	arr[len - 1] = '\0';
	if (strlen(arr + 1) > 1)
	{
		reverse(arr + 1);
	}
	arr[len - 1] = temp;
}
int main()
{
	char arr[] = "abcdefg";
	reverse_string(arr);
	printf("arr = %s\n", arr);
	return 0;
}