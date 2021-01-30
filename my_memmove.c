#include<stdio.h>
#include<assert.h>
void* my_memmove(void* dest, void* sourse, size_t num)
{
	assert(dest != NULL);
	assert(sourse != NULL);
	char* ret = (char*)dest;
	if (sourse > dest && (char*)sourse < (char*)dest + num)
	{
		while (num--)
		{
			*(char*)dest = *(char*)sourse;
			sourse = 1 + (char*)sourse;
			dest = (char*)dest + 1;
		}
		return ret;
	}
	else
	{
		while (num--)
		{
			char* _dest = (char*)dest + num - 1;
			char* _sourse = (char*)sourse + num - 1;
			*_dest = *_sourse;
			_dest++, _sourse++;
		}
		return ret;
	}
}
int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8 };
	int arr2[] = { 9,9,8,7 };
	my_memmove(arr1 + 2, arr1, 16);//1 2 3 4  ¿¼µ½ 3 4 5 6 

	int i;
	for (i = 0; i < sizeof(arr1) / sizeof(arr1[2]); i++)
	{
		printf("%d ", arr1[i]);
	}
	return 0;
}