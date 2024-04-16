#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
struct ElementType
{
	unsigned long ID;
	char *name;
};
typedef struct ElementType *Student;

struct ListInfo
{
	int count;
	int max_size;
	Student *list;
};
typedef struct ListInfo *Class;
typedef int Position;

void Insert(Class cls,Student s,Position p)
{
	Position current;
	if(p>cls->count||cls->count==cls->max_size) return;
	current=cls->count;
	while(current!=p)
	{
		cls->list[current]=cls->list[current-1];
		current--;
	}
	cls->list[current]=s;
	cls->count++;
}

Class CreateClass(int max_size)
{
	Class cls=(Class)malloc(sizeof(struct ListInfo));
	cls->count=0;
	cls->max_size=max_size;
	cls->list=(Student*)malloc(max_size*sizeof(struct ElementType));
	return cls;
}

void display(Class cls){
	Position p;
	for (p = 0;p<cls->count;p++)	
		printf("*** %d | %ld      |%s ***\n",
		p+1,cls->list[p]->ID,cls->list[p]->name);
}

int main()
{
	Class cls10 = CreateClass(MAX_SIZE);
	
	Student std1 = (Student)malloc(sizeof(struct ElementType));
	std1->ID = 102220332;
	std1->name = "Phan Phuoc Nhat";
	
	Student std2 = (Student)malloc(sizeof(struct ElementType));
	std2->ID = 102230177;
	std2->name = "Le Thi Kieu Chi";
	
	Student std3 = (Student)malloc(sizeof(struct ElementType));
	std3->ID = 102230255;
	std3->name = "Nguyen Thi Bao Ngan";
	
	Insert(cls10,std1,0);
	Insert(cls10,std2,1);
	Insert(cls10,std3,0);
	display(cls10);
	std3->ID=1111;
	display(cls10);

	return 0;
}