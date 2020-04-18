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
int palindrome(NODE *head){
    NODE *p=head,*q=NULL,*r;
    if(head==NULL)
      return 0;
    while(p!=q && p->next!=q){
       r=p;
       while(r->next!=q)
          r=r->next;
       q=r;
       if(p->info!=q->info)
         return 0;
       p=p->next;
    }
   return 1;
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
        printf("Enter 2 to check whether list is palindrome or not\n");
        printf("Enter 3 to display a list\n");
        printf("Enter 4 to exit\n");
        scanf("%d",&op);
        if(op==1){
            scanf("%d",&y);
            head=insertFront(head,y);
        }
        else if(op==2){
             if(palindrome(head)==1)
                printf("list is Palindrome\n");
             else
                printf("List is not palindrome\n");
        }
        else if(op==3){
            display(head);
        }
        else
             exit(0);          
     }
}

