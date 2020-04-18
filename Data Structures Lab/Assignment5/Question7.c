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
    NODE *last=head->next;
    for(i=1;i<=n;i++)
    {
   	 printf("Enter the information of node %d: ",i);
   	 scanf("%d",&x);
   	 NODE *p = (NODE*)malloc(sizeof(NODE));
   	 p->info=x;
   	 p->next=NULL;
   	 if(head->next==NULL)
   	 {
   		 p->prev=head;
   		 head->next=p;
   		 last=p;
   	 }
   	 else
   	 {
   		 last->next=p;
   		 p->prev=last;
   		 last=p;
   	 }
    head->info++;
    }
    printf("Doubly linked list created\n");
}

void insert_start()
{
    int x;
    printf("Enter the information of the node that you want to insert ");
    scanf("%d",&x);
    NODE *p=(NODE*)malloc(sizeof(NODE));
    p->info=x;
    p->prev=head;
    if(head->next==NULL)
   	 p->next=NULL;
    else
    {
   	 p->next=head->next;
   	 p->next->prev=p;
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
    p->next=NULL;
    p->info=x;
    if(temp==NULL)
    {
   	 p->prev=head;
   	 head->next=p;
    }
    else
    {    
   	 while(temp->next!=NULL)
   		 temp=temp->next;
   	 temp->next=p;
   	 p->prev=temp;
    }
    printf("\nElement inserted\n");
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
    {
   	 printf("The list is empty. Element not found\n");
   	 return;
    }
    else if(temp->info==x)
    {
   	 p->prev=head;
   	 p->next=head->next;
   	 head->next->prev=p;
   	 head->next=p;
    }
    else
    {
   	 while(temp->next!=NULL && temp->next->info!=x)
   		 temp=temp->next;
   	 if(temp->next==NULL)
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
    {
   	 printf("The list is empty. Element not found\n");
   	 return;
    }
    else
    {
   	 NODE *temp=head->next;
   	 while(temp!=NULL && temp->info!=x)
   		 temp=temp->next;
   	 if(temp==NULL)
   	 {
   		 printf("Element not found\n");
   		 return;
   	 }
   	 else if(temp->next==NULL)
   	 {
   		 temp->next=p;
   		 p->next=NULL;
   		 p->prev=temp;
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
    if(head->next==NULL)
    {
   	 printf("The list is empty\n");
   	 return;
    }
    else if(temp->next==NULL)
    {
   	 free(temp);
   	 head->next=NULL;
    }
    else
    {
   	 head->next=temp->next;
   	 head->next->prev=head;
   	 free(temp);
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
    else
    {
   	 while(temp->next!=NULL)
   		 temp=temp->next;
   	 temp->prev->next=NULL;
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
    if(head->next==NULL)
    {
   	 printf("The list is empty\n");
   	 return;
    }
    else if(temp->next==NULL)
    {
   	 if(temp->info==x)
   	 {
   		 free(temp);
   		 head->next=NULL;
   		 printf("Element deleted\n");
   		 head->info--;
   	 }
   	 else
   		 printf("Element not found\n");
    }
    else if(temp->info==x)
    {
   	 head->next=temp->next;
   	 head->next->prev=head;
   	 free(temp);
   	 printf("Element deleted\n");
   	 head->info--;
    }
    else
    {
   	 while(temp!=NULL && temp->info!=x)
   		 temp=temp->next;
   	 if(temp==NULL)
   		 printf("Element not found\n");
   	 else if(temp->next==NULL)
   	 {
   		 temp->prev->next=NULL;
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
   	 printf("The information of nodes in the doubly linked list are:\n");
   	 while(temp!=NULL)
   	 {
   		 printf("%d\t",temp->info);
   		 temp=temp->next;
   	 }
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
    printf("\nMenu driven program for header doubly linked list\n");
    while(1)
    {
   	 printf("\nEnter 1. to create a header doubly linked list\n");
   	 printf("Enter 2. to insert an element at the start of the header doubly linked list\n");
   	 printf("Enter 3. to insert an element at the end of the header doubly linked list\n");
   	 printf("Enter 4. to insert element before an existing element whose information is x in a header doubly linked list\n");
   	 printf("Enter 5. to insert an element after an existing element whose information is x in a header doubly linked list\n");
   	 printf("Enter 6. to delete the first element of the header doubly linked list\n");
   	 printf("Enter 7. to delete the last element of the header doubly linked list\n");
   	 printf("Enter 8. to delete the element whose information is x from a header doubly linked list\n");
   	 printf("Enter 9. to display the contents of the header doubly linked list\n");
   	 printf("Enter 10. to display the number of elements in the header doubly linked list\n");
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

