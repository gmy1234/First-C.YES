#include"game.h"

//���̳�ʼ����
void intiboard(char board[ROW][COL], int row, int col) 
{
	int j, i;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
			board[i][j] = ' ';
	}

}
/*   ��ӡ����
   |   |
---|---|---
   |   |
---|---|---
   |   |
*/
void display(char board[ROW][COL],int row,int col)
{
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		// ��ӡ��һ�У� 
		for (j = 0; j < COL; j++)
		{
			printf(" %c ",board[i][j]);
			if (j < COL - 1)
				printf("|");
		}
		printf("\n");
		
		//��ӡ�ڶ��У� 
		if (i < ROW - 1)
		{
			for (j = 0; j < COL; j++)
			{
				printf("---");
				if (j < COL - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}


//������壺
void player(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("����ߣ�\n");
	while (1)
	{
		printf("���������꣺ \n");
		scanf("%d,%d", &x, &y);
		if ((x > 0 && x <= row) && (y > 0 && y <= col))
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("�����걻ռ�ã�\n ");
		}
		else
		{
			printf("����������������룡\n");
			break;
		}

	}
}

void computer(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����ߣ�-->\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
// �ж�״̬��
char win(char board[ROW][COL], int row, int col) 
{
	int i=0;
	// ����
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
		
	}
	 //   ����
	for (int j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
			return board[0][j];
	}
	//�Խ���
	if (board[1][1] == board[2][2] && board[1][1] == board[0][0] && board[1][1] != ' ')
		return board[2][2];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[0][2];
	//�ж�ƽ�֣�
	if (1 == full(board, ROW, COL))//      ƽ�֣�@
		return '@';
	else
		return '~';

}

int full(char board[ROW][COL], int row, int col)  // 1 :  man      0 : buman
{
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}

	return 1;
}