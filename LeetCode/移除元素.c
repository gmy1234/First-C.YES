#include<stdio.h>


//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

int removeElement(int* nums, int numsSize, int val)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < numsSize; i++)
    {
	if (nums[i] != val)
	{
	    nums[j] = nums[i];
	    ++j;
	}
    }
    return j;
}

int main()
{
    int nums[6] = { 1,2,3,2,3,4 };
    int val = 3;
    int ret = removeElement(nums, 6, 3);
    int i = 0;
    for (i = 0; i < ret; i++)
	printf("%d ", nums[i]);
}
return 0;
}