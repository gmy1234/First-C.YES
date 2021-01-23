#include<stdio.h>
#include<time.h>
#include<stdlib.h>//srand();

#define ROW 5
#define COL 5

void menu();
void test();
void game();


//声明： 
void intiboard(char board[ROW][COL], int row, int col);

void display(char board[ROW][COL], int row, int col);

void player(char board[ROW][COL],int row,int col);

void computer(char board[ROW][COL], int row, int col);

char win(char board[ROW][COL],int row,int col);


/*四种状态：
电脑赢 ==‘#’
玩家赢==‘*'
平局==‘@’
继续=='~'
	*/

int full(char board[ROW][COL], int row, int col);