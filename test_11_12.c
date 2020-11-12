#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	FILE* pfRead = fopen("text1.txt", "r");
	if (pfRead == NULL)
	{
		perror("open the file for reading");
		return -1;
	}
	FILE* pfWriting = fopen("text2.txt", "w");
	if (pfWriting == NULL)
	{
		perror("open the file for writing");
		fclose(pfRead);
		pfRead = NULL;
		return -1;
	}
	//¿½±´
	int ch = 0;
	while (ch = getc(pfRead) != EOF)
	{
		putc(ch, pfWriting);
	}
	fclose(pfRead);
	pfRead = NULL;
	fclose(pfWriting);
	pfWriting = NULL;
	return 0;
}