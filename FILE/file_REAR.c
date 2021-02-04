int main()
{
	FILE* ptr = fopen("testqqq.txt", "r");
	if (ptr != NULL)
	{
		//读文件
		printf("%c",fgetc( ptr));
		printf("%c", fgetc(ptr));
		printf("%c", fgetc(ptr));
		//关闭文件
		fclose(ptr);
	}

	return 0;
}