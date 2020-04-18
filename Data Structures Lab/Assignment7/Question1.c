#include <stdio.h>
#include <stdlib.h>
struct node{
    int info;
    struct node* next;
};
typedef struct node NODE;

NODE* createNode(int x) {
    NODE* p = (NODE*) malloc(sizeof(NODE));
    p->info = x;
    p->next = NULL;
    return p;
}


NODE* insert(NODE* head, int x) {
    NODE* p = head;
    NODE* q = createNode(x);
    if(head == NULL) {
   	 return q;
    }
    while(p->next != NULL) {
   	 p = p->next;
    }
    p->next = q;
    return head;
}

void display(NODE* head) {
    NODE* p = head;
    printf("Printing rearranged List\n");
    while(p->next != NULL) {
   	 printf("%d\n",p->info);
   	 p = p->next;
    }
    printf("%d\n",p->info);
}

NODE* arrange(NODE* head) {
    NODE* p = head, *q = head;
    while(q->next != NULL) {
   	 p = p->next;
   	 q = (q->next)->next;
    }
    q->next = head;
    head = p->next;
    p->next = NULL;
    return head;
}

int main() {
    NODE* head = NULL;
    int n, x, val;
    printf("Enter The Number of elements of List\n");
    scanf("%d",&n);
    for(x = 0;x < n;x++){
   	 scanf("%d",&val);
   	 head = insert(head,val);
    }
    head = arrange(head);
    display(head);
} 

