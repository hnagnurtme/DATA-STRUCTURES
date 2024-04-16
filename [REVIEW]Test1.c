#include <stdio.h>
#include <stdlib.h>

struct ElementType{
	unsigned long ID;
	char *name;
};

struct Node 
{
	struct ElementType value;
	struct Node *next;
};

typedef struct Node *List;
typedef unsigned int Position;

List InsertListatFront(List pL)
{
	struct ElementType e;
	List newItem=(List)malloc(sizeof(struct Node));
	printf(" Nhap ID ");
	scanf("%u",&e.ID);
	getchar();
	printf(" Nhap Ho va ten ");
	gets(e.name);
	newItem->value=e;
	newItem->next=pL->next;
	pL->next=newItem;
	
	return newItem;
}

void Traveling(List pL)
{
	List temp=pL;
	while(temp!=NULL)
	{
		printf(" **** | %u  |%s         \n",pL->value.ID,pL->value.name);
		temp=temp->next;
	}
}

int main()
{
	List pL=NULL;
	int i=5;
	while(i--)
	{
		pL=InsertListatFront(pL);
	}
	Traveling(pL);
	return 0;
}

