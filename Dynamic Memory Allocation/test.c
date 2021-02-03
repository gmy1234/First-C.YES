#include"contact.h"


void menu()
{
	printf("********************\n");
	printf("********************\n");
	printf("**1.添加    2.删除***\n");
	printf("**3.修改    4.查找***\n");
	printf("**5.显示    6.打印***\n");
	printf("**0退出通讯录********\n");
	printf("********************\n");
	printf("********************\n");
	
}
int main()
{
	int input=0;
	struct contact A;
	//初始化通讯录
	Init(&A);
	do
	{
		menu();
		printf("请选择：\n");
		scanf_s("%d", &input);
		switch (input)
		{
		case ADD:
			Add(&A);
			break;
		case DEL:
			Delcontact(&A);
			break;
		case Modification:
			Modif(&A);
			break;
		case Search:
			SEARCH(&A);
			break;
		case SHOW:
			Show(&A);
			break;
		case Print:
			break;
		case Exit:
			printf("退出\n");
			break;
		default :
			printf("选择错误：\n");

		}
	} while (input);

	
	return 0;
}