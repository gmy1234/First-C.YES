#include<stdio.h>
#include<stdlib.h>

//#define MAXSIZE 10
typedef int stackDataType;
typedef struct stackNode {
	stackDataType data;
	stackNode* next;
}stackNode;

//初始化
void InitStack(stackNode* head);
//打印 
void stackPrint(stackNode* head);
//开辟新得入栈元素
stackNode* BuynewNodeStack(stackDataType x);

//增	  --入栈
void stackPush(stackNode** head, stackDataType x);
//删  --出栈
void stackPop(stackNode** head);


//清空栈

//销毁栈

void test1()
{
	stackNode* head = NULL;
	stackPush(&head, 0);
	stackPush(&head, 1);
	stackPush(&head, 2);
	stackPush(&head, 3);
	stackPush(&head, 4);
	stackPrint(head);

	stackPop(&head);
	stackPrint(head);
}
int main()
{

	test1();

	return 0;
}


//初始化
void InitStack(stackNode* head)
{
	head = NULL;
}
//创建新得
stackNode* BuynewNodeStack(stackDataType x)
{
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
	if (newNode == NULL)
	{
		printf("开辟失败\n");
		return NULL;
	}
	newNode->data = x;
	return newNode;
}


//入栈
void stackPush(stackNode** head, stackDataType x)
{
	
	stackNode* newEle = BuynewNodeStack(x);
	newEle->next = *head;
	*head = newEle; 
}

//打印
void stackPrint(stackNode* head)
{
	stackNode* cur = head;
	while (cur != NULL)
	{
		printf("%d", cur->data);

		cur = cur->next;
		printf("\n");
	}
	printf("\n");

}

//出栈

void stackPop(stackNode** head)
{
	//判断栈是否为空
	if (head == NULL)
	{
		return;
	}

	stackNode* cur = *head;
	stackNode* Next = (*head)->next;

	free(cur);
	*head = Next;

}