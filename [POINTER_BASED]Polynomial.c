#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node{
	int coeff;
	unsigned int expo;
	struct Node *next;
};
typedef struct Node *POLYNOMIAL;
typedef struct Node *POSITION;

POLYNOMIAL CreatePolynomial()
{
	POLYNOMIAL headerNode=(POLYNOMIAL)malloc(sizeof(struct Node));
	headerNode->expo=INT_MAX;
	headerNode->next=NULL;
	return headerNode;
}


void InsertPolynomial(POLYNOMIAL poly,int coeff,unsigned int expo)
{	
	POSITION prev;
	prev=poly;
	while(poly!=NULL&&poly->expo>=expo)
	{
		prev=poly;
		poly=poly->next;
	}
	if(prev->expo==expo) prev->coeff+=coeff;
	else
	{
		POSITION newItem =(POSITION)malloc(sizeof(struct Node));
		newItem->coeff=coeff;
		newItem->expo=expo;
		newItem->next=prev->next;
		prev->next=newItem;
	}
}
void display_polynomial(POLYNOMIAL poly){
	poly = poly->next;
	while (poly!=NULL)
	{
		printf(" %dx^%d ",poly->coeff,poly->expo);
		poly=poly->next;
	}
	printf("\n");
}

void AddPolynomial(POLYNOMIAL poly1,POLYNOMIAL poly2,POLYNOMIAL polysum)
{
	poly1 = poly1->next;
	while(poly1!=NULL)
	{
		InsertPolynomial(polysum,poly1->coeff,poly1->expo);
		poly1=poly1->next;
	}
	poly2 = poly2->next;
	while(poly2!=NULL)
	{
		InsertPolynomial(polysum,poly2->coeff,poly2->expo);
		poly2=poly2->next;
	}
}

void MultiPolynomial(POLYNOMIAL poly1,POLYNOMIAL poly2,POLYNOMIAL polyprod)
{
	poly1=poly1->next;
	poly2=poly2->next;
	while(poly1!=NULL)
	{
		while(poly2!=NULL)
		{
			InsertPolynomial(polyprod,poly1->coeff*poly2->coeff,poly1->expo+poly2->expo);
			poly2=poly2->next;

		}
		poly1=poly1->next;
	}

}
int main (){
	POLYNOMIAL poly1 = CreatePolynomial();
	POLYNOMIAL poly2 = CreatePolynomial();
	POLYNOMIAL polysum = CreatePolynomial();
	POLYNOMIAL polyprod = CreatePolynomial();
	
	InsertPolynomial(poly1,10,1000);
	InsertPolynomial(poly1,5,14);
	InsertPolynomial(poly1,1,0);
	InsertPolynomial(poly1,5,15);
	InsertPolynomial(poly2,10,10);
	InsertPolynomial(poly2,52,14);
	InsertPolynomial(poly2,122,0);
	InsertPolynomial(poly2,54,15);
	
	display_polynomial(poly1);
	display_polynomial(poly2);
	AddPolynomial(poly1,poly2,polysum);
	MultiPolynomial(poly1,poly2,polyprod);
	display_polynomial(polysum);
	display_polynomial(polyprod);
	return 0;
}