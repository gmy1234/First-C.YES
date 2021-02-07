#include"contact.h"

void Init(struct contact* st)
{
	memset(st->data, 0, sizeof(st->data));
	st->size = 0;

}

void Add(struct contact* st)
{
	if (st->size == MAX)
		printf("通讯录已满\n");
	else
	{
		printf("姓名：->");
		scanf("%s", st->data[st->size].name);
		printf("年龄：->");
		scanf("%d", st->data[st->size].age);
		printf("性别：->");
		scanf("%s", st->data[st->size].sex);
		printf("电话：->");
		scanf("%s", st->data[st->size].tele);
		printf("地址：->");
		scanf("%s", st->data[st->size].address);

		st->size++;
		printf("添加完成\n");
		
	}
}

void Show(struct contact* ft)
{
	if (ft->size == 0)
		printf("通讯录为空：\n");
	else
	{
		printf("%s\t%s\t%s\t%s\t%s\n", "姓名","年龄", " 性别 ","电话","住址");
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


// 查找封装函数：
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
	printf("请输入删除的姓名：->");
	scanf("%s", name);

	//查找
	pos = Find_Peo(qt, name);
	if (pos == -1)
	{
		printf("删除的人不存在：\n");
	}
	else
	{
		//删除：
		int j;
		for (j = pos; j < qt->size - 1; j++)
		{
			qt->data[j] = qt->data[j + 1];
		}
		qt->size--;
		printf("删除已完成\n");
	}
}

// 修改：
void Modif(struct contact* wt)
{
	char name[MAX_NAME];
	printf("请输入修改的姓名：->");
	scanf("%s", name);

	int pos2 = Find_Peo(wt, name);
	if (pos2 == -1)
		printf("无此人，修改失败!\n");
	else
	{
		printf("姓名：->");
		scanf("%s", wt->data[pos2].name);
		printf("年龄：->");
		scanf("%d", wt->data[pos2].age);
		printf("性别：->");
		scanf("%s", wt->data[pos2].sex);
		printf("电话：->");
		scanf("%s", wt->data[pos2].tele);
		printf("地址：->");
		scanf("%s", wt->data[pos2].address);

		printf("添加完成\n");
	}
}

void SEARCH(struct contact* et)
{
	//查找；
	char name[MAX_NAME];
	printf("请输入要查找的姓名：->");
	scanf("%s", name);
		
	int pos = Find_Peo(et, name);
	if (pos == -1)
		printf("无此人\n");
	else
	{

		printf("%s\t%s\t%s\t%s\t%s\n", "姓名", "年龄", " 性别 ", "电话", "住址");
		printf("%s\t%d\t%s\t%s\t%s \n",
			et->data[pos].name,
			*(et->data[pos].age),
			et->data[pos].sex,
			et->data[pos].tele,
			et->data[pos].address);
	}
}