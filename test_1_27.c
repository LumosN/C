/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* sortArray(int* nums, int numsSize, int* returnSize){
	*returnSize = numsSize;
	//��gap���õĴ�һ�㣬Ȼ��Ԥ����������ӽ�����
	//���gap==1��ֱ�Ӳ������򣬱�֤����
	int gap = numsSize;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//gapһֱ�ǵݼ�����̬�� +1����֤���һ��gapһ����1������ʵ����ȫ����   
		for (int i = 0; i < numsSize - gap; i++) // i++ʵ�ֶ��鲢��
		{
			//forѭ���ڲ��ǵ����ڲ�������
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