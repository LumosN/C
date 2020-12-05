int removeDuplicates(int* nums, int numsSize){
    int i = 0,j = 0;
    if(numsSize<2)
    {
        return numsSize;
    }
    for(i=1;i<numsSize;i++)
    {
        if(nums[i] != nums[j])
        {
            nums[++j] = nums[i]; 
        }
    }
    return ++j;
}
