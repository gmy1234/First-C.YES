
#include<string.h>
#include<stdio.h>

#define MAX_NAME 20
#define MAX_TELE 13
#define ADDRESS 20
#define MAX 100

struct People_information {
	char name[MAX_NAME];
	char age[3];
	char sex[4];
	char tele[MAX_TELE];
	char address[ADDRESS];

};

struct contact {
	struct People_information data[MAX];
	int size;
};

enum fun {
	Exit,
	ADD,
	DEL,
	Modification,
	Search,
	SHOW,
	Print
};

void Init(struct contact* st);//��ʼ��

void Add(struct contact* dt);//����

void Show(struct contact* ft);//��ʾ

void Delcontact(struct contact* qt);//ɾ��

void Modif(struct contact* wt);//�޸�

void SEARCH(struct contact* et);//����