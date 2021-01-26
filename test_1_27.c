/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* sortArray(int* nums, int numsSize, int* returnSize){
	*returnSize = numsSize;
	//把gap设置的大一点，然后预排序，让数组接近有序
	//最后gap==1，直接插入排序，保证有序
	int gap = numsSize;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//gap一直是递减的形态； +1：保证最后一次gap一定是1，才能实现完全排序   
		for (int i = 0; i < numsSize - gap; i++) // i++实现多组并排
		{
			//for循环内部是单组内部的排序
			int end = i;
			int temp = nums[end + gap];
			while (end >= 0)
			{
				if (temp < nums[end])
				{
					nums[end + gap] = nums[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			nums[end + gap] = temp;
		}
	}
	return nums;
}