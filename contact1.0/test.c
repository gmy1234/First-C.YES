#include"contact.h"


void menu()
{
	printf("********************\n");
	printf("********************\n");
	printf("**1.���    2.ɾ��***\n");
	printf("**3.�޸�    4.����***\n");
	printf("**5.��ʾ    6.��ӡ***\n");
	printf("**0�˳�ͨѶ¼********\n");
	printf("********************\n");
	printf("********************\n");
	
}
int main()
{
	int input=0;
	struct contact A;
	//��ʼ��ͨѶ¼
	Init(&A);
	do
	{
		menu();
		printf("��ѡ��\n");
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
			printf("�˳�\n");
			break;
		default :
			printf("ѡ�����\n");

		}
	} while (input);

	
	return 0;
}