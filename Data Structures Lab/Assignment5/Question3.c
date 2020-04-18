#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node *next;
};
typedef struct node NODE;


NODE* createList() {
	NODE *head = (NODE*) malloc(sizeof(NODE));
	head->next = NULL;
	return head;
}

NODE* insertFront(NODE* head, int x){
	NODE *p = (NODE*) malloc(sizeof(NODE));
	p->info = x;
	if(head->next != NULL) {
    	p->next = (head->next);
	}else {
    	p->next = NULL;
	}
	head->next = p;
   // printf("%d",head->next);
	return head;
}

NODE* insertEnd(NODE* head, int x){
	NODE *q = (NODE*) malloc(sizeof(NODE));
	NODE *p = head;
	while(p->next != NULL) {
    	p = p->next;
	}
	p->next = q;
	q->info = x;
	q->next = NULL;
	return head;
}

NODE* insertBefore(NODE* head, int x, int val) {
	NODE* p = head, *q;
	while(p->info != x || p->next != NULL) {
    	q = p;
    	p = p->next;
	}
	if(p->info == x) {
    	NODE* a = (NODE*) malloc(sizeof(NODE));
    	if(head->next == p) {
        	head->next = a;
    	}
    	a->info = x;
    	a->next = q->next;
    	a->next = p;
    	return head;
	}else {
    	printf("The Given Value was not found in the List.... Please try again\n");
    	return head;
	}
}

NODE *insertX(NODE *head, int val, int x) {
	NODE *p = head;
	NODE *q = (NODE *) malloc(sizeof(NODE));
	while (p->info != x || p->next != NULL) {
    	p = p->next;
	}
	if (p->info == x) {
    	q->next = p->next;
    	q->info = val;
    	p->next = q;
    	return head;
	}
}

void display(NODE* head) {
	NODE *p = head;
	if(p->next == NULL) {
    	printf("No Elements in List\n");
	}else {
    	p=p->next;
    	while (p->next != NULL) {
        	printf("%d\n", p->info);
        	p = p->next;
    	}
    	printf("%d\n", p->info);
	}
}

NODE* deleteStart(NODE* head){
	NODE *p = head->next;
	if(p->next == NULL) {
    	printf("There Are No elements in the List\n");
    	return head;
	}
	if((p->next)->next == NULL) {
    	printf("The Deleted Element is %d \n",p->info);
    	free(p);
    	head->next = NULL;
    	return head;
	}
	head->next = p->next;
	printf("The Deleted Element is %d \n",p->info);
	free(p);
	return head;
}

NODE* deleteEnd(NODE* head){
	NODE *p = head, *q;
	if(p->next == NULL) {
    	printf("There Are No elments in the List\n");
    	return head;
	}
	p = head->next;
	while(p->next != NULL) {
    	q->next = p;
    	p = p->next;
	}
	if(head->next == p) {
    	head->next == NULL;
    	return head;
	}
	q->next = NULL;
	printf("The Deleted Element is %d \n",p->info);
	free(p);
	return head;
	}

void main() {
	NODE *head;
	int n, val, x;
	head = createList();
	while(1) {
    	printf("Welcome to Linked List\n");
    	printf("Select a operation\n");
    	printf("1.INSERT AT START\n2.INSERT AT END\n3.INSERT AFTER X\n4.DELETE AT START\n5.DELETE AT END\n6.DELETE X\n7.DISPLAY LIST\n8.EXIT\n9.INSERT BEFORE X");
    	scanf("%d", &n);
    	switch (n) {
        	case 1:
            	printf("Enter the element\n");
            	scanf("%d", &val);
            	head = insertFront(head, val);
            	if(head->next == NULL) {
                	printf("%d\t",head->info);
            	}
            	break;
        	case 2:
            	printf("Enter the element\n");
            	scanf("%d", &val);
            	head = insertEnd(head, val);
            	break;
        	case 3:
            	printf("Enter The Element after which the number should be inserted\n");
            	scanf("%d", &x);
            	printf("Enter The Element to be Inserted\n");
            	scanf("%d", &val);
            	head = insertX(head, val, x);
            	break;
        	case 4:
            	head = deleteStart(head);
            	break;
        	case 5:
            	head = deleteEnd(head);
            	break;
        	case 6:
            	printf("Enter The Element which is to be Deleted\n");
            	scanf("%d", &x);
          	//  head = deleteX(head, x);
            	break;
        	case 7:
            	display(head);
            	break;
        	case 8:
            	return;
        	case 9:
            	printf("Enter The Number to be inserted\n");
            	scanf("%d",&x);
            	printf("Enter The Value Before which element should be inserted\n");
            	scanf("%d",&val);
            	head  = insertBefore(head, x, val);
            	break;
        	default:
            	break;
    	}
	}
}

