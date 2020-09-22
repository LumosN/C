#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//void towers(int n, char A, char B, char C)
//{
//	if (n == 1)
//	{
//		printf("move desk 1 from %c to %c\n", A , C);
//	}
//	towers(n - 1, A, B, C);
//	printf("move desk %d from %c to %c", n, A, C);
//	towers(n - 1, B, C, A);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	towers(n, 'A', 'C', 'B');
//	return 0;
//}
void towers(int n, char A, char C, char B)
{
	if (n == 1)		//递归出口
	{
		printf("move disk 1 from peg %c to peg %c\n",
			A, C);
		return;
	}
	//把n-1个圆盘从A借助C移至B
	towers(n - 1, A, B, C);
	//把圆盘n由A直接移至C
	printf("move disk %d from peg %c to peg %c\n", n, A, C);
	//把n-1个圆盘从B借助A移至C
	towers(n - 1, B, C, A);
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	towers(n, 'A', 'C', 'B');
	return 0;
}