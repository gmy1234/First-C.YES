#include<stdio.h>
#include<malloc.h>



//给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
//初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。你可以假设 nums1 的空间大小等于 m + n，


//方法一：
//以空间换时间的方法，O（m+n） 开辟新得空间
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {

    int* temp = (int*)malloc(sizeof(int) * (m + n));
    int n1 = 0;
    int n2 = 0;
    int i = 0;
    while (n1 < m && n2 < n)
    {
	if (nums1[n1] < nums2[n2])
	{
	    temp[i++] = nums1[n1++];

	}
	else
	{
	    temp[i++] = nums2[n2++];

	}
    }
    while (n1 < m)
    {
	temp[i++] = nums1[n1++];

    }
    while (n2 < n)
    {
	temp[i++] = nums2[n2++];

    }
    memcpy(nums1, temp, sizeof(int) * (m + n));

    free(temp);
    temp = NULL;
}

//方法二：
//
int main()
{
    int nums1[6] = { 1,2,3,0,0,0 };
    int nums2[3] = { 2,5,6 };
    merge(nums1, 6, 3, nums2, 3, 3);
    int i = 0;
    for (i = 0; i < 6; i++)
    {
	printf("%d ", nums1[i]);
    }
    return 0;
}


