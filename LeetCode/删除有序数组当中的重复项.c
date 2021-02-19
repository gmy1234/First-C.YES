#include<stdio.h>

// ����һ���������飬����Ҫ�� ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�
//��Ҫʹ�ö��������ռ䣬������� ԭ�� �޸��������� ����ʹ�� O(1) ����ռ�����������.

int removeDuplicates(int* nums, int numSize)
{
    int fast = 1;	//��ָ��
    int slow = 0;	//��ָ��
    if (numSize == 0)
	return 0;
    for (fast = 1; fast < numSize; fast++)
    {
	if (nums[fast] != nums[slow])	//��ʾ�ظ��������Ѿ������һ��
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