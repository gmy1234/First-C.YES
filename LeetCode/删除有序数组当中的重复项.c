#include<stdio.h>

// 给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
//不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成.

int removeDuplicates(int* nums, int numSize)
{
    int fast = 1;	//快指针
    int slow = 0;	//慢指针
    if (numSize == 0)
	return 0;
    for (fast = 1; fast < numSize; fast++)
    {
	if (nums[fast] != nums[slow])	//表示重复的数字已经是最后一个
	{
	    ++slow;
	    nums[slow] = nums[fast];
	}
    }
    return slow + 1;


}

int main()
{
    int nums[10] = { 0,0,1,1,1,2,2,3,3,4 };
    int ret = removeDuplicates(nums, 10);
    int i = 0;
    for (i = 0; i < ret; i++)
    {
	printf("%d ", nums[i]);
    }
    return 0;
}