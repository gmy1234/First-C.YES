#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct strStack
{
	char str[20];
	int top;		//ջ
}cStack;

//��ʼ��
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

//��ջ
char stackPop(cStack* s)
{
	if (s->top == 0)
		return '!';
	s->top--;
	return s->str[s->top];
}

//����һ��
//ȫ����ջ֮��,��ȡ��ջ����ȡ�����ַ����к�֮ǰ������Ƿ���ͬ��
//eg:abba   ��ջ��a-b-b-a      ��ջ��a-b-b-a

//int main()
//{
//	char Popch[20]={'\0'};
//	char ch[20]={'\0'};
//	printf("������Ҫ�жϵ��ַ���\n");
//	scanf("%s",&ch);
//
//	cStack* s = (cStack*)malloc(sizeof(cStack));
//	InitStack(s);
//
//	int sLength=0;	//�ַ����еĳ���
//	sLength=strlen(ch);
//	for (int i = 0; i < sLength; i++)
//	{
//		stackPush(s, ch[i]);	//��ջ
//	}
//
//	//��ջ��
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
//		printf("�ǻ���\n");
//	else
//		printf("���ǻ���\n");
//
//		return 0;
//}


//��������
//ѹ��һ����ַ�

int main()
{
	char ch[20] = { '\0' };
	printf("������Ҫ�жϵ��ַ����У�\n");
	scanf("%s", ch);
	int length = strlen(ch);
	cStack* s = (cStack*)malloc(sizeof(cStack));
	InitStack(s);

	char chPop[20] = { '\0' };
	int tag = 0;
	if (length % 2 == 0)//ż��
	{
		//��ջ
		for (int i = 0; i < length / 2; i++)
		{
			stackPush(s, ch[i]);
		}
		//��ջ
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
		//��ջ
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
		printf("�ǻ���\n");
	else
		printf("���ǻ���\n");
	return 0;
}