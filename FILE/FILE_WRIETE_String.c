#include<stdio.h>

int main()
{
	char T[20] = "ancdf";
	FILE* prw = fopen("test.txt", "w");
	if (prw == NULL)
	{
		perror("hh");
	}
	else
		//дһ��
	{
		fgets(T, prw);
		fgets("gmy", prw);

		//�ر��ļ�
		fclose(prw);
		prw = NULL;
	}
	return 0;
}