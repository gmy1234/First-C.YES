#include<stdio.h>
#include<time.h>
#include<stdlib.h>//srand();

#define ROW 5
#define COL 5

void menu();
void test();
void game();


//������ 
void intiboard(char board[ROW][COL], int row, int col);

void display(char board[ROW][COL], int row, int col);

void player(char board[ROW][COL],int row,int col);

void computer(char board[ROW][COL], int row, int col);

char win(char board[ROW][COL],int row,int col);


/*����״̬��
����Ӯ ==��#��
���Ӯ==��*'
ƽ��==��@��
����=='~'
	*/

int full(char board[ROW][COL], int row, int col);