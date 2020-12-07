int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
{
	//计算一下K是多少位
	int Ksize = 0;
	int Knum = K;
	while (Knum)
	{
		++Ksize;
		Knum /= 10;
	}
	//我们要算一下 要开多大的空间来存放新的数组
	int len = ASize > Ksize ? ASize : Ksize;
	int* retArr = (int*)malloc(sizeof(int)*(len + 1));//开空间
	int Ai = ASize - 1;//A数组的下标控制
	int reti = 0;//新的数组的下标控制
	int nextNum = 0;  //进位
	while (len--)//要加几次 就是 循环的的次数
	{
		int a = 0;
		if (Ai >= 0)//这里要控制的原因是怕K的位数多于数组A元素个数，导致Ai为负数
		{
			a = A[Ai];
			Ai--;
		}
		int ret = a + K % 10 + nextNum;//加上进位
		K /= 10;
		if (ret>9)
		{
			ret = ret - 10;
			nextNum = 1;
		}
		else
		{
			nextNum = 0;
		}
		retArr[reti] = ret;
		++reti;
	}
	if (nextNum == 1)//万一又多了一位呢
	{
		retArr[reti] = 1;
		reti++;
	}
	//逆置
	int left = 0, right = reti - 1;
	while (left <= right)
	{
		int temp = retArr[left];
		retArr[left] = retArr[right];
		retArr[right] = temp;
		left++;
		right--;
	}
	*returnSize = reti;
	return retArr;
}