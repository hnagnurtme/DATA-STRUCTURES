#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_DEGREE 100
typedef struct polynomial{
	int coeff_array[MAX_DEGREE+1];
	unsigned int high_power;
} *POLYNOMIAL ;

void ZeroPolynomial(POLYNOMIAL poly)
{
	for(int i=0;i<=MAX_DEGREE;i++) poly->coeff_array[i]=0;
		poly->high_power=0;
}

void AddPolynomial(POLYNOMIAL poly1,POLYNOMIAL poly2,POLYNOMIAL polysum)
{
	ZeroPolynomial(polysum);
	polysum->high_power=fmax(poly1->high_power,poly2->high_power);
	for(int i=0;i<=polysum->high_power;i++)
	{
		polysum->coeff_array[i]=poly1->coeff_array[i]+poly2->coeff_array[i];
	}
}


void MultiPolynomial(POLYNOMIAL poly1,POLYNOMIAL poly2,POLYNOMIAL polyprod)
{
	ZeroPolynomial(polyprod);
	polyprod->high_power=poly1->high_power+poly2->high_power;
	for(int i=0;i<=poly1->high_power;i++)
	{
		for(int j=0;j<=poly2->high_power;j++)
		{
			polyprod->coeff_array[i+j]+=poly1->coeff_array[i]*poly2->coeff_array[j];
		}
	}
}
void display_polynomial(POLYNOMIAL poly){
	for (int i=poly->high_power;i>=0;i--){
		if (poly->coeff_array[i]==0)
			continue;
		if (poly->coeff_array[i]>0)
		{
			if (i!=poly->high_power)
				printf(" + ");
		} else {
			if (i!=poly->high_power)
				printf(" - ");
			else
				printf("-");
		}
		
		if (abs(poly->coeff_array[i])!=1 && i>0)
			printf("%d",abs(poly->coeff_array[i]));
		else if (i==0)
			printf("%d",abs(poly->coeff_array[i]));
			
		if (i!=0)
			printf("x");
		if (i>1)
			printf("^%d",i);		
	}
	printf("\n");
}

int main()
{
	POLYNOMIAL poly1=(POLYNOMIAL)malloc(sizeof(struct polynomial));
	POLYNOMIAL poly2=(POLYNOMIAL)malloc(sizeof(struct polynomial));
	POLYNOMIAL polysum=(POLYNOMIAL)malloc(sizeof(struct polynomial));
	POLYNOMIAL polyprod=(POLYNOMIAL)malloc(sizeof(struct polynomial));
	ZeroPolynomial(poly1);
	ZeroPolynomial(poly2);
	poly1->high_power = 3;
	poly1->coeff_array[0] = -1;poly1->coeff_array[1] = 0;
	poly1->coeff_array[2] = 4;poly1->coeff_array[3] = -1;
	poly2->high_power = 2;
	poly2->coeff_array[0] = 5;poly2->coeff_array[1] = 1;
	poly2->coeff_array[2] = 4;
	AddPolynomial(poly1,poly2,polysum);
	MultiPolynomial(poly1,poly2,polyprod);
	display_polynomial(poly1);
	display_polynomial(poly2);
	display_polynomial(polysum);
	display_polynomial(polyprod);
	return 0;
}