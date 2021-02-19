/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* plusOne(int* digits, int digitsSize, int* returnSize){
	int i = digitsSize - 1;//从最后一位开始
	if (digits[i] < 9)
	{
		digits[i]++;
	}
	else // == 9
	{
		while (digits[i] == 9)
		{
			digits[i] = 0;
			i--;
			if (i < 0)
			{
				break;
			}
		}
		if (i >= 0)
		{
			digits[i]++;
		}
	}

	if (digits[0] == 0) //说明进位了
	{
		*returnSize = digitsSize + 1;
		int* a = (int*)malloc(sizeof(int)*(digitsSize + 1));
		a[0] = 1;
		for (int i = 1; i <= digitsSize; i++)
		{
			a[i] = digits[i - 1];
		}
		return a;
	}
	else
	{
		*returnSize = digitsSize;
		int* a = (int*)malloc(sizeof(int)*(digitsSize));
		for (int i = 0; i < digitsSize; i++)
		{
			a[i] = digits[i];
		}
		return a;
	}
}