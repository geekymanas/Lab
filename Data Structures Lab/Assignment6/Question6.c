#include<stdio.h>
#include<stdlib.h>
struct node{
   int info;
   struct node *next;
};
typedef struct node NODE;
NODE* insertFront(NODE *head,int y){
      NODE *p;
      p=(NODE *)malloc(sizeof(NODE));
      p->info=y;
      p->next=head;
      return p;
}
NODE *reverse(NODE *head){
      NODE *prev=NULL,*cur=head,*next;
      while(cur!=NULL){
           next=cur->next;
           cur->next=prev;
           prev=cur;
           cur=next;
       } 
       return prev;  
}
void display(NODE *head){
     NODE *p;
     for(p=head;p!=NULL;p=p->next)
        printf("%d\t",p->info);
     printf("\n");
}
void main(){
   NODE *head=NULL;
   int op,y;
     while(1){
        printf("Enter 1 to Insert an element in the sorted linked list.\n");
        printf("Enter 2 to reverse a linked list\n");
        printf("Enter 3 to display a linked list\n");
        printf("Enter 4 to exit\n");
        scanf("%d",&op);
        if(op==1){
            scanf("%d",&y);
            head=insertFront(head,y);
        }
        else if(op==2){
             head=reverse(head);
        }
        else if(op==3){
            display(head);
        }
        else
             exit(0);          
     }
}

