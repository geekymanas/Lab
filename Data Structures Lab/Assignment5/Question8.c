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
    printf("Enter the number of nodes in the linked list ");
    scanf("%d",&n);
    NODE *last=head->next;
    for(i=1;i<=n;i++)
    {
   	 printf("Enter the information of node %d: ",i);
   	 scanf("%d",&x);
   	 NODE *p = (NODE*)malloc(sizeof(NODE));
   	 p->info=x;
   	 if(head->next==NULL)
   	 {
   		 p->next=p;
   		 p->prev=head;
   		 head->next=p;
   		 last=p;
   	 }
   	 else
   	 {
   		 last->next=p;
   		 p->prev=last;
   		 p->next=head->next;
   		 head->next->prev=p;
   		 last=p;
   	 }
   	 head->info++;
    }
    printf("\nHeader circular doubly linked list created\n");
}

void insert_start()
{
    int x;
    printf("Enter the information of the node that you want to insert ");
    scanf("%d",&x);
    NODE *p, *temp;
    p=(NODE*)malloc(sizeof(NODE));
    temp=head->next;
    p->info=x;
    if(head->next==NULL)
    {
   	 p->prev=head;
   	 p->next=p;
    }
    else
    {    
   	 p->next=head->next;
   	 while(temp->next!=head->next)
   		 temp=temp->next;
   	 temp->next=p;
   	 p->prev=temp;
    }
    head->next=p;
    printf("Element inserted\n");
    head->info++;
}

void insert_end()
{
    int x;
    printf("Enter the information of the node that you want to insert ");
    scanf("%d",&x);
    NODE *p, *temp;
    p=(NODE*)malloc(sizeof(NODE));
    temp=head->next;
    p->info=x;
    if(head->next==NULL)
    {
   	 p->next=p;
   	 p->prev=head;
   	 head->next=p;
   	 printf("The list was empty initially. This is the first element\n");
    }
    else
    {    
   	 while(temp->next!=head->next)
   		 temp=temp->next;
   	 temp->next=p;
   	 p->prev=temp;
   	 p->next=head->next;
   	 head->next->prev=p;
   	 printf("\nElement inserted\n");
    }
    head->info++;
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
    temp=head->next;
    p->info=y;
    if(head->next==NULL)
   	 printf("The list is empty. Element not found\n");
    else if(head->next->info==x)
    {
   	 p->next=head->next;
   	 while(temp->next!=head->next)
   		 temp=temp->next;
   	 temp->next=p;
   	 p->prev=temp;
   	 head->next=p;
    }
    else
    {
   	 while(temp->next!=head->next && temp->next->info!=x)
   		 temp=temp->next;
   	 if(temp->next==head->next)
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
    head->info++;
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
    if(head->next==NULL)
   	 printf("The list is empty. Element not found\n");
    else if(head->next->next==head->next)
    {
   	 if(head->next->info==x)
   	 {    
   		 p->prev=head->next;
   		 p->next=head->next;
   		 head->next->prev=p;
   		 head->next->next=p;
   	 }
   	 else
   	 {
   		 printf("Element not found\n");
   		 return;
   	 }
    }
    else if(head->next->info==x)
    {
   	 p->prev=head->next;
   	 p->next=head->next->next;
   	 head->next->next=p;
   	 p->next->prev=p;
    }
    else
    {
   	 NODE *temp=head->next->next;
   	 while(temp!=head->next && temp->info!=x)
   		 temp=temp->next;
   	 if(temp==head->next)
   	 {
   		 printf("Element not found\n");
   		 return;
   	 }
   	 else if(temp->next==head->next)
   	 {
   		 p->next=head->next;
   		 p->prev=temp;
   		 temp->next=p;
   		 head->next->prev=p;
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
    head->info++;
}

void delete_first()
{
    NODE *temp=head->next;
    if(temp==NULL)
    {
   	 printf("The list is empty\n");
   	 return;
    }
    else if(temp->next==temp)
    {
   	 free(temp);
   	 head->next=NULL;
    }
    else
    {
   	 NODE *temp1=head->next;
   	 while(temp->next!=head->next)
   		 temp=temp->next;
   	 head->next=head->next->next;
   	 temp->next=head->next;
   	 head->next->prev=temp;
   	 free(temp1);
    }
    printf("First element deleted\n");
    head->info--;
}

void delete_last()
{
    NODE *temp=head->next;
    if(temp==NULL)
    {
   	 printf("The list is empty\n");
   	 return;
    }
    if(temp->next==temp)
    {
   	 free(temp);
   	 head->next=NULL;
    }
    else
    {
   	 while(temp->next!=head->next)
   		 temp=temp->next;
   	 temp->prev->next=head->next;
   	 head->next->prev=temp->prev;
   	 free(temp);
    }
    printf("Last element deleted\n");
    head->info--;
}

void delete_x()
{
    int x;
    printf("Enter information of the node to be deleted ");
    scanf("%d",&x);
    NODE *temp=head->next;
    if(temp==NULL)
    {
   	 printf("The list is empty\n");
   	 return;
    }
    else if(temp->next==temp)
    {
   	 if(temp->info==x)
   	 {
   		 head->next=NULL;
   		 free(temp);
   		 printf("Element deleted\n");
   		 head->info--;
   	 }
   	 else
   		 printf("Element not found\n");
    }
    else if(temp->info==x)
    {
   	 NODE *temp1=head->next;
   	 while(temp->next!=head->next)
   		 temp=temp->next;
   	 head->next=head->next->next;
   	 temp->next=head->next;
   	 head->next->prev=temp;
   	 free(temp1);
   	 printf("Element deleted\n");
   	 head->info--;
    }
    else
    {
   	 temp=temp->next;
   	 while(temp!=head->next && temp->info!=x)
   		 temp=temp->next;
   	 if(temp==head->next)
   		 printf("Element not found\n");
   	 else if(temp->next==head->next)
   	 {
   		 temp->prev->next=head->next;
   		 head->next->prev=temp->prev;
   		 free(temp);    
   		 printf("Element deleted\n");
   		 head->info--;
   	 }
   	 else
   	 {
   		 temp->prev->next=temp->next;
   		 temp->next->prev=temp->prev;
   		 free(temp);
   		 printf("Element deleted\n");
   		 head->info--;
   	 }
    }
}

void display()
{
    NODE *temp=head->next;
    if(head->next==NULL)
   	 printf("\nList is empty");
    else
    {
   	 printf("The information of nodes in the header circular doubly linked list are:\n");
   	 do{
   		 printf("%d\t",temp->info);
   		 temp=temp->next;
   	 }while(temp!=head->next);
    }
    printf("\n");
}

void display_num()
{
    printf("\nThe number of nodes in the header doubly linked list = %d\n",head->info);
}

int main()
{
    NODE head1;
    head1.next=NULL;
    head1.prev=NULL;
    head1.info=0;
    head=&head1;
    int n;
    printf("\nMenu driven program for header circular doubly linked list\n");
    while(1)
    {
   	 printf("\nEnter 1. to create a header circular doubly linked list\n");
   	 printf("Enter 2. to insert an element at the start of the header circular doubly linked list\n");
   	 printf("Enter 3. to insert an element at the end of the header circular doubly linked list\n");
   	 printf("Enter 4. to insert element before an existing element whose information is x in a header circular doubly linked list\n");
   	 printf("Enter 5. to insert an element after an existing element whose information is x in a header circular doubly linked list\n");
   	 printf("Enter 6. to delete the first element of the header circular doubly linked list\n");
   	 printf("Enter 7. to delete the last element of the header circular doubly linked list\n");
   	 printf("Enter 8. to delete the element whose information is x from a header circular doubly linked list\n");
   	 printf("Enter 9. to display the contents of the header circular doubly linked list\n");
   	 printf("Enter 10. to display the number of elements in the header circular doubly linked list\n");
   	 printf("Enter 11. to exit\n\n");
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
   		 case 10: display_num();
   				  break;
   		 case 11: printf("Exiting\n\n");
   				  exit(1);
   		 default: printf("Invalid entry. Enter a number between 1 to 11\n");
   	 }
    }
    return 0;
}

