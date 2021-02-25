/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
	int flag = 0;
	*returnSize = 2;
	int *a = (int*)malloc(sizeof(int)* 2);
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] == target)
		{
			a[0] = i;
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		a[0] = -1;
	}
	flag = 0;
	for (int i = numsSize - 1; i >= 0; i--)
	{
		if (nums[i] == target)
		{
			a[1] = i;
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		a[1] = -1;
	}
	return a;
}