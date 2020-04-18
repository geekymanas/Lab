#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int key;
	char name[20];
	struct node *next;
};
typedef struct node NODE;
int HashFunction(int key,int n);
void insert(int key,NODE *p);
void display(int key,NODE *p);
void delete(int key,NODE *p);
void main()
{
	int n,i;
	printf("Enter no. of places:");
	scanf("%d",&n);
	NODE a[n];
	for(i=0;i<n;i++)
	{
		a[i].next=NULL;
		a[i].key=-1;
	}
	int key,choice;
	printf("\n1.INSERT RECORDS\t2.SHOW RECORD\t3.DELETE RECORDS\t4.EXIT\n");
	while(1)
	{
		printf("Enter choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter key to insert new record:");
					scanf("%d",&key);
					i=HashFunction(key,n);
					insert(key,&a[i]);
					break;
			case 2:printf("Enter key of the record which you want to see:");
					scanf("%d",&key);
					i=HashFunction(key,n);
					display(key,&a[i]);
					break;
			case 3:printf("Enter key of the records which you want to delete:");
					scanf("%d",&key);
					i=HashFunction(key,n);
					delete(key,&a[i]);
					break;
			case 4:exit(1);
		}
	}
}

void insert(int key,NODE *p)
{
	if(p->key==-1&&p->next==NULL)
	{
		p->key=key;
		printf("Enter Employee name:");
		scanf("%s",p->name);
		p->next=NULL;
	}
	else 
	{
		while(p->next!=NULL)
			p=p->next;
		p->next=(NODE*)malloc(sizeof(NODE));
		p=p->next;
		p->key=key;
		printf("Enter Employee name:");
		scanf("%s",p->name);
		p->next=NULL;
	}
}

void display(int key,NODE *p)
{
	while(p->key!=key)
		p=p->next;
	printf("Record is:\nKey:\t%d\n",p->key);
	puts(p->name);
}

void delete(int key,NODE *p)
{
	if(p==NULL)
		printf("Record not found");
	else if(p->key==key&&p->next==NULL)
		p=NULL;
	else
	{
		while(p->next->key!=key)
			p=p->next;
		NODE *q=p->next->next;
		free(p->next);
		p->next=q;
	}
}
		
int HashFunction(int key,int n)
{
	return key%n;
}

