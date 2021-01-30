#include<stdio.h>
#include<assert.h>

void* my_memcpy(void* dest, void* sourse, size_t num)
{
	assert(dest != NULL);
	assert(sourse != NULL);
	char* ret = (char*)dest;
	char* _dest = (char*)dest;
	char* _sourse = (char*)sourse;
	while (num--)
	{
		*_dest = *_sourse;
		_dest++, _sourse++;

	}

	return ret;
}

int main()
{
	int arr1[] = { 1,2,3,4,5,6,6 };
	int arr2[] = { 9,9,8,7 };
	my_memcpy(arr1, arr2, sizeof(arr2));
	int i;
	for (i = 0; i < sizeof(arr1) / sizeof(arr1[2]); i++)
	{
		printf("%d ", arr1[i]);
	}
	return 0;
}