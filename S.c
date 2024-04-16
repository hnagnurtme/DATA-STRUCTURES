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

typedef struct Node *LIST;
typedef struct Node *POSITION;

POSITION Insert(LIST *pL,struct ElementType e,POSITION p)
{
	POSITION newItem=(POSITION)malloc(sizeof(struct Node));
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

void Delete(POSITION p)
{
	if(p==NULL) return;
	p->prev->next=p->next;
	if(p->next!=NULL)
	{
		p->next->prev=p->prev;
	}
	free(p);

}

void display(LIST pL)
{
	int count=1;
	pL=pL->next;
	while(pL!=NULL)
	{
		printf("*** %d | ID: %ld       | Name: %s ***\n",count, pL->value.ID, pL->value.name);
        count++;
        pL = pL->next;
	}
}

LIST CreateList()
{
	LIST headerNode=(LIST)malloc(sizeof(struct Node));
	headerNode->next=NULL;
	headerNode->prev=NULL;
	return headerNode;
}
int main() {
    LIST pL = CreateList();
    struct ElementType item1, item2, item3;
    item1.ID = 1001; item1.name = "Nguyen Van An";
    item2.ID = 1002; item2.name = "Nguyen Van Binh";
    item3.ID = 1003; item3.name = "Nguyen Van Chau";
    POSITION p;
    p = Insert(&pL, item1, pL);
    p = Insert(&pL, item2, p);
    p = Insert(&pL, item3, p);
    display(pL);

   	Delete(p);
    printf("After deleting!\n");
    display(pL);
    POSITION temp;
    while (pL != NULL) {
        temp = pL;
        pL = pL->next;
        free(temp);
    }

    return 0;
}