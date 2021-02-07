#include"contact.h"

void Init(struct contact* st)
{
	memset(st->data, 0, sizeof(st->data));
	st->size = 0;

}

void Add(struct contact* st)
{
	if (st->size == MAX)
		printf("ͨѶ¼����\n");
	else
	{
		printf("������->");
		scanf("%s", st->data[st->size].name);
		printf("���䣺->");
		scanf("%d", st->data[st->size].age);
		printf("�Ա�->");
		scanf("%s", st->data[st->size].sex);
		printf("�绰��->");
		scanf("%s", st->data[st->size].tele);
		printf("��ַ��->");
		scanf("%s", st->data[st->size].address);

		st->size++;
		printf("������\n");
		
	}
}

void Show(struct contact* ft)
{
	if (ft->size == 0)
		printf("ͨѶ¼Ϊ�գ�\n");
	else
	{
		printf("%s\t%s\t%s\t%s\t%s\n", "����","����", " �Ա� ","�绰","סַ");
		int i = 0;
		for (i = 0; i < ft->size; i++)
		{
			printf("%s\t%d\t%s\t%s\t%s \n",
				ft->data[i].name,
				*(ft->data[i].age),
				ft->data[i].sex,
				ft->data[i].tele,
				ft->data[i].address);
		}
	}
}


// ���ҷ�װ������
static int Find_Peo(struct contact* zt, char name1[MAX_NAME])
{
	int i;
	for (i = 0; i < zt->size; i++)
	{
		if (0 == strcmp(zt->data[i].name, name1))
		{
			return i;
		}
	}
	return -1;
}

void Delcontact(struct contact* qt)
{
	int pos = 0;
	char name[MAX_NAME];
	printf("������ɾ����������->");
	scanf("%s", name);

	//����
	pos = Find_Peo(qt, name);
	if (pos == -1)
	{
		printf("ɾ�����˲����ڣ�\n");
	}
	else
	{
		//ɾ����
		int j;
		for (j = pos; j < qt->size - 1; j++)
		{
			qt->data[j] = qt->data[j + 1];
		}
		qt->size--;
		printf("ɾ�������\n");
	}
}

// �޸ģ�
void Modif(struct contact* wt)
{
	char name[MAX_NAME];
	printf("�������޸ĵ�������->");
	scanf("%s", name);

	int pos2 = Find_Peo(wt, name);
	if (pos2 == -1)
		printf("�޴��ˣ��޸�ʧ��!\n");
	else
	{
		printf("������->");
		scanf("%s", wt->data[pos2].name);
		printf("���䣺->");
		scanf("%d", wt->data[pos2].age);
		printf("�Ա�->");
		scanf("%s", wt->data[pos2].sex);
		printf("�绰��->");
		scanf("%s", wt->data[pos2].tele);
		printf("��ַ��->");
		scanf("%s", wt->data[pos2].address);

		printf("������\n");
	}
}

void SEARCH(struct contact* et)
{
	//���ң�
	char name[MAX_NAME];
	printf("������Ҫ���ҵ�������->");
	scanf("%s", name);
		
	int pos = Find_Peo(et, name);
	if (pos == -1)
		printf("�޴���\n");
	else
	{

		printf("%s\t%s\t%s\t%s\t%s\n", "����", "����", " �Ա� ", "�绰", "סַ");
		printf("%s\t%d\t%s\t%s\t%s \n",
			et->data[pos].name,
			*(et->data[pos].age),
			et->data[pos].sex,
			et->data[pos].tele,
			et->data[pos].address);
	}
}