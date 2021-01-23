
#include"game.h"

int main()
{
	
	test();
	

	return 0;
}

//游戏的算法：
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };//棋盘全为0； 
	//初始化棋盘
	intiboard(board, ROW, COL);
	//打印棋盘：
	display(board,ROW,COL);
	//下棋
	while (1) 
	{
		// 玩家下棋：
		player(board, ROW, COL);
		display(board, ROW, COL);
		//  判断player输赢：
		ret = win(board, ROW, COL);
		if (ret != '~')
		{
			break;
		}
		//电脑下棋：
		computer(board, ROW, COL);
		display(board, ROW, COL);
		//  判断comeputer输赢：
		ret = win(board,ROW,COL);
		if (ret != '~')
		{
			break;
		}

	}
	if (ret == '#')
	{
		printf("电脑赢！ \n");

	}
	else if (ret == '*')
	{
		printf("玩家赢！\n");
	}
	else
	{
		printf("平局！ \n");
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
	srand((unsigned int) time(NULL));//调用随机数rand（）的条件； 
	do
	{
		menu();
		printf("1--->开始\n");
		scanf("%d",&p);
		switch (p)
		{
			case 1:
				printf("三子棋：  \n");
				game();
				break;
			case 0:
				printf("退出！\n");
				break;
			default:
				printf("选择错误，请重新选择：\n");
				break;

		}


	} while (p);


}