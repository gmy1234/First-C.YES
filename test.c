
#include"game.h"

int main()
{
	
	test();
	

	return 0;
}

//��Ϸ���㷨��
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };//����ȫΪ0�� 
	//��ʼ������
	intiboard(board, ROW, COL);
	//��ӡ���̣�
	display(board,ROW,COL);
	//����
	while (1) 
	{
		// ������壺
		player(board, ROW, COL);
		display(board, ROW, COL);
		//  �ж�player��Ӯ��
		ret = win(board, ROW, COL);
		if (ret != '~')
		{
			break;
		}
		//�������壺
		computer(board, ROW, COL);
		display(board, ROW, COL);
		//  �ж�comeputer��Ӯ��
		ret = win(board,ROW,COL);
		if (ret != '~')
		{
			break;
		}

	}
	if (ret == '#')
	{
		printf("����Ӯ�� \n");

	}
	else if (ret == '*')
	{
		printf("���Ӯ��\n");
	}
	else
	{
		printf("ƽ�֣� \n");
	}
		

}

void menu()
{
	printf("***************************\n");
	printf("********1.PLAY 0.EXIT  ****\n");
	printf("***************************\n");

}

void test()
{
	int p = 0;
	srand((unsigned int) time(NULL));//���������rand������������ 
	do
	{
		menu();
		printf("1--->��ʼ\n");
		scanf("%d",&p);
		switch (p)
		{
			case 1:
				printf("�����壺  \n");
				game();
				break;
			case 0:
				printf("�˳���\n");
				break;
			default:
				printf("ѡ�����������ѡ��\n");
				break;

		}


	} while (p);


}