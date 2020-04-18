#include<stdio.h>
#include<stdlib.h>
struct node{
  int info;
  struct node *next;
};
typedef struct node NODE;
int count(NODE *head){
    if(head==NULL)
       return 0; 
    return (1+count(head->next));
}
NODE* insertFront(NODE *head,int y){
      NODE *p;
      p=(NODE *)malloc(sizeof(NODE));
      p->info=y;
      p->next=head;
      return p;
}
NODE* deleteFront(NODE *head){
     NODE *p=head;
     if(head==NULL){
        printf("List is empty\n");
        return head;
     }
     head=head->next;
     free(p);
     return head;
}
void main(){
   NODE *head=NULL;
   int op,y;
     while(1){
        printf("Enter 1 to Insert an element in the linked list.\n");
        printf("Enter 2 to delete the element from the linked list\n");
        printf("Enter 3 to count the no of elements of the linked list\n");
        printf("Enter 4 to exit\n");
        scanf("%d",&op);
        if(op==1){
            scanf("%d",&y);
            head=insertFront(head,y);
        }
        else if(op==2)
             head=deletestart(head);
        else if(op==3)
             printf("%d\n",count(head));
        else
             exit(0);  
     }
}

