#include<stdio.h>
#include<stdlib.h>

typedef struct doubly_linked_list{
    int info;
    struct doubly_linked_list *next;
    struct doubly_linked_list *prev;
} NODE;

NODE *head;

void create()
{
    int n,i,x;
    printf("Enter the number of nodes in the linked list\n");
    scanf("%d",&n);
    NODE *last=head;
    for(i=1;i<=n;i++)
    {
   	 printf("Enter the information of node %d: ",i);
   	 scanf("%d",&x);
   	 NODE *p = (NODE*)malloc(sizeof(NODE));
   	 p->info=x;
   	 if(head==NULL)
   	 {
   		 p->next=p;
   		 p->prev=NULL;
   		 head=p;
   		 last=p;
   	 }
   	 else
   	 {
   		 last->next=p;
   		 p->prev=last;
   		 p->next=head;
   		 head->prev=p;
   		 last=p;
   	 }
    }
    printf("\nDoubly ciruclar linked list created\n");
}

void insert_start()
{
    int x;
    printf("Enter the information of the node that you want to insert ");
    scanf("%d",&x);
    NODE *p, *temp;
    p=(NODE*)malloc(sizeof(NODE));
    temp=head;
    p->info=x;
    if(head==NULL)
    {
   	 p->prev=NULL;
   	 p->next=p;
    }
    else
    {    
   	 p->next=head;
   	 head->prev=p;
   	 while(temp->next!=head)
   		 temp=temp->next;
   	 p->prev=temp;
   	 temp->next=p;
    }
    head=p;
    printf("Element inserted\n");
}

void insert_end()
{
    int x;
    printf("Enter the information of the node that you want to insert ");
    scanf("%d",&x);
    NODE *p, *temp;
    p=(NODE*)malloc(sizeof(NODE));
    temp=head;
    p->info=x;
    if(head==NULL)
    {
   	 p->next=p;
   	 p->prev=NULL;
   	 head=p;
   	 printf("The list was empty initially. This is the first element\n");
    }
    else if(head->next==head)
    {
   	 p->prev=head;
   	 p->next=head;
   	 head->next=p;
   	 head->prev=p;
   	 printf("Element inserted\n");
    }
    else
    {    
   	 while(temp->next!=head)
   		 temp=temp->next;
   	 temp->next=p;
   	 p->prev=temp;
   	 p->next=head;
   	 head->prev=p;
   	 printf("\nElement inserted\n");
    }
}

void insert_before()
{
    int x,y;
    printf("Enter x ");
    scanf("%d",&x);
    printf("Enter the information of the element that you want to insert ");
    scanf("%d",&y);
    NODE *p, *temp;
    p=(NODE*)malloc(sizeof(NODE));
    temp=head;
    p->info=y;
    if(head==NULL)
    {
   	 printf("The list is empty. Element not found\n");
   	 return;
    }
    else if(head->info==x)
    {
   	 p->next=head;
   	 head->prev=p;
   	 while(temp->next!=head)
   		 temp=temp->next;
   	 temp->next=p;
   	 p->prev=temp;
   	 head=p;
    }
    else
    {
   	 while(temp->next!=head && temp->next->info!=x)
   		 temp=temp->next;
   	 if(temp->next==head)
   	 {
   		 printf("Element not found\n");
   		 return;
   	 }
   	 p->prev=temp;
   	 p->next=temp->next;
   	 temp->next=p;
   	 p->next->prev=p;
    }
    printf("Element inserted\n");
}

void insert_after()
{
    int x,y;
    NODE* p=(NODE*)malloc(sizeof(NODE));
    printf("Enter x ");
    scanf("%d",&x);
    printf("Enter information of the new node to be inserted ");
    scanf("%d",&y);
    p->info=y;
    if(head==NULL)
    {
   	 printf("The list is empty. Element not found\n");
   	 return;
    }
    else if(head->next==head)
    {
   	 if(head->info==x)
   	 {    
   		 p->prev=head;
   		 p->next=head;
   		 head->prev=p;
   		 head->next=p;
   	 }
   	 else
   	 {
   		 printf("Element not found\n");
   		 return;
   	 }
    }
    else if(head->info==x)
    {
   	 p->prev=head;
   	 p->next=head->next;
   	 head->next=p;
   	 p->next->prev=p;
    }
    else
    {
   	 NODE *temp=head->next;
   	 while(temp!=head && temp->info!=x)
   		 temp=temp->next;
   	 if(temp==head)
   	 {
   		 printf("Element not found\n");
   		 return;
   	 }
   	 else if(temp->next==head)
   	 {
   		 p->next=head;
   		 p->prev=temp;
   		 temp->next=p;
   		 head->prev=p;
   	 }
   	 else
   	 {
   		 p->prev=temp;
   		 p->next=temp->next;
   		 temp->next=p;
   		 p->next->prev=p;
   	 }
    }
    printf("Element inserted\n");
}

void delete_first()
{
    NODE *temp=head;
    if(head==NULL)
    {
   	 printf("The list is empty\n");
   	 return;
    }
    else if(head->next==head)
    {
   	 free(temp);
   	 head=NULL;
    }
    else
    {
   	 NODE *temp1=head;
   	 while(temp->next!=head)
   		 temp=temp->next;
   	 head=head->next;
   	 temp->next=head;
   	 head->prev=temp;
   	 free(temp1);
    }
    printf("First element deleted\n");
}

void delete_last()
{
    NODE *temp=head;
    if(head==NULL)
    {
   	 printf("The list is empty\n");
   	 return;
    }
    if(head->next==head)
    {
   	 free(temp);
   	 head=NULL;
    }
    else
    {
   	 while(temp->next!=head)
   		 temp=temp->next;
   	 temp->prev->next=head;
   	 head->prev=temp->prev;
   	 free(temp);
    }
    printf("Last element deleted\n");
}

void delete_x()
{
    int x;
    printf("Enter information of the node to be deleted ");
    scanf("%d",&x);
    NODE *temp=head;
    if(head==NULL)
    {
   	 printf("The list is empty\n");
   	 return;
    }
    else if(head->next==head)
    {
   	 if(head->info==x)
   	 {
   		 free(temp);
   		 head=NULL;
   		 printf("Element deleted\n");
   	 }
   	 else
   		 printf("Element not found\n");
    }
    else if(head->info==x)
    {
   	 NODE *temp1=head;
   	 while(temp->next!=head)
   		 temp=temp->next;
   	 head=head->next;
   	 temp->next=head;
   	 head->prev=temp;
   	 free(temp1);
   	 printf("Element deleted");
    }
    else
    {
   	 temp=temp->next;
   	 while(temp!=head && temp->info!=x)
   		 temp=temp->next;
   	 if(temp==head)
   		 printf("Element not found\n");
   	 else if(temp->next==head)
   	 {
   		 temp->prev->next=head;
   		 head->prev=temp->prev;
   		 free(temp);    
   		 printf("Element deleted\n");
   	 }
   	 else
   	 {
   		 temp->prev->next=temp->next;
   		 temp->next->prev=temp->prev;
   		 free(temp);
   		 printf("Element deleted\n");
   	 }
    }
}

void display()
{
    NODE *temp=head;
    if(head==NULL)
   	 printf("\nList is empty");
    else
    {
   	 printf("The information of nodes in the circular doubly linked list are:\n");
   	 do{
   		 printf("%d\t",temp->info);
   		 temp=temp->next;
   	 }while(temp!=head);
    }
    printf("\n");
}

int main()
{
    head=NULL;
    int n;
    printf("\nMenu driven program for doubly linked list\n");
    while(1)
    {
   	 printf("\nEnter 1. to create a doubly linked list\n");
   	 printf("Enter 2. to insert an element at the start of the doubly linked list\n");
   	 printf("Enter 3. to insert an element at the end of the doubly linked list\n");
   	 printf("Enter 4. to insert element before an existing element whose information is x in a doubly linked list\n");
   	 printf("Enter 5. to insert an element after an existing element whose information is x in a doubly linked list\n");
   	 printf("Enter 6. to delete the first element of the doubly linked list\n");
   	 printf("Enter 7. to delete the last element of the doubly linked list\n");
   	 printf("Enter 8. to delete the element whose information is x from a doubly linked list\n");
   	 printf("Enter 9. to display the contents of the doubly linked list\n");
   	 printf("Enter 10. to exit\n\n");
   	 scanf("%d",&n);
   	 switch(n)
   	 {
   		 case 1: create();
   				 break;
   		 case 2:    insert_start();
   				 break;
   		 case 3: insert_end();
   				 break;
   		 case 4: insert_before();
   				 break;
   		 case 5: insert_after();
   				 break;
   		 case 6: delete_first();
   				 break;
   		 case 7: delete_last();
   				 break;
   		 case 8: delete_x();
   				 break;
   		 case 9: display();
   				 break;
   		 case 10: printf("Exiting\n\n");
   				  exit(1);
   		 default: printf("Invalid entry. Enter a number between 1 to 10\n");
   	 }
    }
    return 0;
}

