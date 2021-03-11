#include<stdio.h>
#include<stdlib.h>

//#define MAXSIZE 10
typedef int stackDataType;
typedef struct stackNode {
	stackDataType data;
	stackNode* next;
}stackNode;

//��ʼ��
void InitStack(stackNode* head);
//��ӡ 
void stackPrint(stackNode* head);
//�����µ���ջԪ��
stackNode* BuynewNodeStack(stackDataType x);

//��	  --��ջ
void stackPush(stackNode** head, stackDataType x);
//ɾ  --��ջ
void stackPop(stackNode** head);


//���ջ

//����ջ

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


//��ʼ��
void InitStack(stackNode* head)
{
	head = NULL;
}
//�����µ�
stackNode* BuynewNodeStack(stackDataType x)
{
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
	if (newNode == NULL)
	{
		printf("����ʧ��\n");
		return NULL;
	}
	newNode->data = x;
	return newNode;
}


//��ջ
void stackPush(stackNode** head, stackDataType x)
{
	
	stackNode* newEle = BuynewNodeStack(x);
	newEle->next = *head;
	*head = newEle; 
}

//��ӡ
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

//��ջ

void stackPop(stackNode** head)
{
	//�ж�ջ�Ƿ�Ϊ��
	if (head == NULL)
	{
		return;
	}

	stackNode* cur = *head;
	stackNode* Next = (*head)->next;

	free(cur);
	*head = Next;

}