#include <stdio.h>
#include <stdlib.h>
struct Elementtype
{
	int value;
};
struct Node
{
	struct Elementtype e;
	struct Node *next;
};

 typedef struct Node *Stack;
 typedef struct Node *Stacknode;

 Stack creat_stack()
 {
 	Stack S=(Stack)malloc(sizeof(Stack));
 	S->next=NULL;
 	return S;
 }

 int is_empty(Stack S)
 {
 	if(S==NULL) 
 		{
 			printf(" You must use creat_stack function first");
 			return 0;
 		}
 	return 1;
 }
 void make_null(Stack S)
 {
 	if(S==NULL) printf(" You must use creat_stack function first");
 	else 
 	S->next=NULL;
 }


Stack push(Stack S,struct Elementtype e)
 {
 	Stack newstack=(Stack)malloc(sizeof(struct Node));
 	newstack->e=e;
 	newstack->next=S->next;
 	S->next=newstack;
 	return newstack;
 }
void pop(Stack S,struct Elementtype e)
 {
 	if(is_empty(S))
 	{
 		Stacknode Node_top=S->next;
 		S->next=S->next->next;
 		free(Node_top);
 	}
 	else
 	{
 		printf(" The stack is empty");
 	}

 }

Stack Node_top(Stack S)
{
	if(is_empty(S))
	{
		printf(" The stack is empty");
		return NULL;
	}
	else 
	{
		return S->next;
	}
}


void display(Stack S)
{
	if(is_empty(S))
	{
		printf(" The stack is empty");
	}
	else 
	{
		S=S->next;
		printf(" Curremt state of the stack is ");
		while(S!=NULL)
		{
			printf(" %4d ",S->e.value);
			S=S->next;
		}
	}

}

int main()
{
	Stack S=NULL;
	Elementtype M;
	M.value=10;
	S=push(S,M);
	display(S);
	return 0;
}