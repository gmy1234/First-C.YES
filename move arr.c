#include<stdio.h>
void move(int a[], int cd)
{
	int left, right;
	left = 0;
	right = cd - 1;
	while (left < right)
	{
		//×ó±ßÕÒÅ¼Êý£º
		while ((left < right)&& arr[left] % 2 == 1)
		{
			left++;
		}
		//´ÓÓÒ±ßÕÒÆæÊý£º
		while ((left < right)&& arr[right] % 2 == 0)
		{
			right++;
		}
		if (left < right)
		{
			int t = arr[left];
			arr[left] = arr[right];
			arr[right] = t;
		}
	}
}
int main()
{
	int i;
	int arr[10] = { 1,5,2,3,4,7,8,9,0,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	move(arr, sz);
	for (i = 0; i < sz; i++)
		printf("%d ", arr[i]);
	return 0;
}