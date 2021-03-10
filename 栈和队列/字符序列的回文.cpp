#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct strStack
{
	char str[20];
	int top;		//栈
}cStack;

//初始化
void InitStack(cStack* s)
{
	s->top = 0;
}

void stackPush(cStack* s, char c)
{
	if (s->top == 49)
		return;
	s->str[s->top] = c;
	s->top++;

}

//出栈
char stackPop(cStack* s)
{
	if (s->top == 0)
		return '!';
	s->top--;
	return s->str[s->top];
}

//方法一：
//全部入栈之后,在取出栈。看取出的字符序列和之前的相比是否相同。
//eg:abba   入栈：a-b-b-a      出栈：a-b-b-a

//int main()
//{
//	char Popch[20]={'\0'};
//	char ch[20]={'\0'};
//	printf("请输入要判断的字符：\n");
//	scanf("%s",&ch);
//
//	cStack* s = (cStack*)malloc(sizeof(cStack));
//	InitStack(s);
//
//	int sLength=0;	//字符序列的长度
//	sLength=strlen(ch);
//	for (int i = 0; i < sLength; i++)
//	{
//		stackPush(s, ch[i]);	//入栈
//	}
//
//	//出栈：
//	for (int i = 0; i < sLength; i++)
//	{
//		Popch[i]= stackPop(s);
//	}
//	
//	int tag=0;
//	for (int j = 0; j < sLength; j++)
//	{
//		if(ch[j]==Popch[j])
//			tag=1;
//		else
//		{
//			tag=-1;
//		}
//	}
//	
//	if(tag==1)
//		printf("是回文\n");
//	else
//		printf("不是回文\n");
//
//		return 0;
//}


//方法二：
//压入一半的字符

int main()
{
	char ch[20] = { '\0' };
	printf("请输入要判断的字符序列：\n");
	scanf("%s", ch);
	int length = strlen(ch);
	cStack* s = (cStack*)malloc(sizeof(cStack));
	InitStack(s);

	char chPop[20] = { '\0' };
	int tag = 0;
	if (length % 2 == 0)//偶数
	{
		//入栈
		for (int i = 0; i < length / 2; i++)
		{
			stackPush(s, ch[i]);
		}
		//出栈
		for (int j = 0; j < length / 2; j++)
		{
			chPop[j] = stackPop(s);

			if (ch[j + (length / 2)] == chPop[j])
				tag = 1;
			else
				tag = 0;
		}
	}
	else
	{
		for (int i = 0; i < length / 2 + 1; i++)
		{
			stackPush(s, ch[i]);
		}
		//出栈
		for (int j = 0; j < length / 2 + 1; j++)
		{
			chPop[j] = stackPop(s);
			if (chPop[j] == ch[j + length / 2])
				tag = 1;
			else
				tag = 0;
		}
	}

	if (tag == 1)
		printf("是回文\n");
	else
		printf("不是回文\n");
	return 0;
}