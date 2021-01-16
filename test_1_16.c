/**
* Note: The returned array must be malloced, assume caller calls free().
*/
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child<n)
	{
		if (child + 1<n&&a[child]<a[child + 1])
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			int temp = a[child];
			a[child] = a[parent];
			a[parent] = temp;
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
	*returnSize = k;
	if (k == 0)
	{
		return NULL;
	}
	int* retArr = (int*)malloc(sizeof(int)*k);
	//建k个数的大堆
	int i, j;
	for (i = 0; i < k; i++)
	{
		retArr[i] = arr[i];
	}
	for (i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(retArr, k, i);
	}
	for (j = k; j<arrSize; j++)//从数组中第k+1个数开始与堆顶元素相比
	{
		if (arr[j]<retArr[0])
		{
			retArr[0] = arr[j];//覆盖掉
			AdjustDown(retArr, k, 0);
		}
	}
	return retArr;
}