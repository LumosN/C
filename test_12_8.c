int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
{
	//����һ��K�Ƕ���λ
	int Ksize = 0;
	int Knum = K;
	while (Knum)
	{
		++Ksize;
		Knum /= 10;
	}
	//����Ҫ��һ�� Ҫ�����Ŀռ�������µ�����
	int len = ASize > Ksize ? ASize : Ksize;
	int* retArr = (int*)malloc(sizeof(int)*(len + 1));//���ռ�
	int Ai = ASize - 1;//A������±����
	int reti = 0;//�µ�������±����
	int nextNum = 0;  //��λ
	while (len--)//Ҫ�Ӽ��� ���� ѭ���ĵĴ���
	{
		int a = 0;
		if (Ai >= 0)//����Ҫ���Ƶ�ԭ������K��λ����������AԪ�ظ���������AiΪ����
		{
			a = A[Ai];
			Ai--;
		}
		int ret = a + K % 10 + nextNum;//���Ͻ�λ
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
	if (nextNum == 1)//��һ�ֶ���һλ��
	{
		retArr[reti] = 1;
		reti++;
	}
	//����
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