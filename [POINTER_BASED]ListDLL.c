#include <stdio.h>
#include <stdlib.h>

struct ElementType{
	unsigned long ID;
	char *name;
};

struct Node{
	struct ElementType value;
	struct Node *next;
	struct Node *prev;
};

typedef struct Node *List;
typedef struct Node *Position;

Position Insert(List *pL,struct ElementType e,Position p)
{
	Position newItem=(Position)malloc(sizeof(struct Node));
	newItem->value=e;
	newItem->next=p->next;
	newItem->prev=p;
	p->next=newItem;
	if(newItem->next!=NULL)
	{
		newItem->next->prev=newItem;
	}
	return newItem;
}

void display(List pL)
{
	int count=1;
	pL=pL->next;
	while(pL!=NULL)
	{
		printf(" **** %d | %8u     |%s     \n",count,pL->value.ID,pL->value.name);
		count++;
		pL=pL->next;
	}
}

void delet(Position p)
{
	if(p==NULL) return ;
	p->prev->next=p->next;
	if(p->next!=NULL)
	p->next->prev=p->prev;
	free(p);
}
List createList()
{
	Position headerNode=(Position)malloc(sizeof(struct Node));
	headerNode->next=NULL;
	return headerNode;
}

int main()
{
	List pL=createList();
	struct ElementType item1,item2;
	item1.ID=10001;item1.name="Trinh Giao Linh";
	item2.ID=10002;item2.name="Nguyen Trung Anh";
	Position p;
	p=Insert(&pL,item1,pL);
	p=Insert(&pL,item2,pL);
	display(pL);
	delet(p);
	display(pL);
	free(pL);
	return 0;


}