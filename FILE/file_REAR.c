int main()
{
	FILE* ptr = fopen("testqqq.txt", "r");
	if (ptr != NULL)
	{
		//���ļ�
		printf("%c",fgetc( ptr));
		printf("%c", fgetc(ptr));
		printf("%c", fgetc(ptr));
		//�ر��ļ�
		fclose(ptr);
	}

	return 0;
}