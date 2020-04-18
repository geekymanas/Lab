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
NODE* duplicate(NODE *head){
   NODE *p=head,*q=head->next;
   while(q!=NULL){
      if(p->info==q->info){
         p->next=q->next;
         free(q);
         q=p->next;
      }
      else {
        p=p->next;
        if(p==NULL)
          return head;
        q=p->next;
        }
   }
   return head;
}
void display(NODE *head){
     NODE *p;
     for(p=head;p!=NULL;p=p->next)
        printf("%d\t",p->info);
}
void main(){
   NODE *head=NULL;
   int op,y;
     while(1){
        printf("Enter 1 to Insert an element in the sorted linked list.\n");
        printf("Enter 2 to remove duplicate values\n");
        printf("Enter 3 to display a list\n");
        printf("Enter 4 to exit\n");
        scanf("%d",&op);
        if(op==1){
            scanf("%d",&y);
            head=insertFront(head,y);
        }
        else if(op==2){
            head=duplicate(head);
        }
        else if(op==3){
            display(head);
        }
        else
             exit(0);          
     }
}

