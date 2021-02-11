#include<stdio.h>

int main() {
    int arr[5] = { 1,2,3,5,0 };
    //计算数组的和

    /*int i = 0;
    int sum = 0;
    int sum1 = 0;
    for (i = 0; i < 5; i++)
    {
	    sum = arr[i] + sum;
    }
    for (i = 0; i < 6; i++)
    {
	    sum1 = i + sum1;
    }
    printf("%d ", sum1 - sum);
    return 0;*/

    // 异或：
    int x = 0;
    int j = 0;
    int i = 0;
    for (j = 0; j < 5; j++)
    {
	x = x ^ arr[j];
    }
    for (i = 0; i < 6; i++)
    {
	x = x ^ i;
    }
    printf("%d ", x);
    return 0;

}