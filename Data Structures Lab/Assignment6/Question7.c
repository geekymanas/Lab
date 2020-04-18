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
NODE *merge(NODE *head1,NODE *head2){
      NODE *p=head1,*q=head2,*head=NULL;
      while(p!=NULL && q!=NULL){
          NODE *r=(NODE *)malloc(sizeof(NODE)),*t=head;
          r->next=NULL;
          if(p->info>q->info){
             r->info=q->info;
             q=q->next;
          }
          else if(p->info<q->info){
             r->info=p->info;
             p=p->next;
          }
          else {
             r->info=p->info;
             p=p->next;
             q=q->next;
          }
          if(head==NULL){
             head=r;  
          }
          else{
          while(t->next!=NULL)
                t=t->next;
          t->next=r;
          }
      }
      while(p!=NULL){
          NODE *r=(NODE *)malloc(sizeof(NODE)),*t=head;
          r->info=p->info;
          r->next=NULL;
          while(t->next!=NULL)
             t=t->next;
          t->next=r;
          p=p->next;
      }
      while(q!=NULL){
          NODE *r=(NODE *)malloc(sizeof(NODE)),*t=head;
          r->info=q->info;
          r->next=NULL;
          while(t->next!=NULL)
             t=t->next;
          t->next=r;
          q=q->next;
       }
      return head;
}
void display(NODE *head){
     NODE *p;
     for(p=head;p!=NULL;p=p->next)
        printf("%d\t",p->info);
     printf("\n");
}
void main(){
   NODE *head1=NULL;
   NODE *head2=NULL;
   NODE *head=NULL;
   int op,y;
      while(1){
        printf("Enter 1 to Insert an element in the first linked list.\n");
        printf("Enter 2 to Insert an element in the second linked list.\n");
        printf("Enter 3 to merge two linked lists\n");
        printf("Enter 4 to display a list\n");
        printf("Enter 5 to exit\n");
        scanf("%d",&op);
        if(op==1){
            scanf("%d",&y);
            head1=insertFront(head1,y);
        }
        else if(op==2){
            scanf("%d",&y);
            head2=insertFrontf(head2,y);
        }
        else if(op==3){
            head=merge(head1,head2);
        }
        else if(op==4){
            printf("Enter 1 to display first list 2 to display second list and 3 to display merged list.\n");
            scanf("%d",&y);
            if(y==1) 
               display(head1);
            else if(y==2)
               display(head2);
            else if(y==3)
               display(head);
            else
               printf("Wrong number entered!!");
        }
        else
             exit(0);          
     }
}

