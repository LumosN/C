#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define Offsetof(structname,membername) (int)(&(((structname*)0)->membername)) 
struct test
{
	char c1;
	int i;
	char c2;
};
int main()
{
	printf("%d \n", Offsetof(struct test, i));
	return 0;
}
