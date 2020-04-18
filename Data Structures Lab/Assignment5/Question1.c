#include <stdio.h>
#include <stdlib.h>
struct node {
	int info;
	struct node *next;
};
typedef struct node NODE;

NODE* insertBefore(NODE* head, int x, int val) {
	if(head == NULL) {
    	printf("NO LIST CREATED \n");
    	return NULL;
	}
	else {
    	NODE* p = head, *q;
    	while(p->info != x || p->next != NULL) {
            	q = p;
            	p = p->next;
    	}
    	if(p->info == x) {
        	NODE* a = (NODE*) malloc(sizeof(NODE));
        	a->info = x;
        	a->next = q->next;
        	a->next = p;
        	return head;
    	}else {
        	printf("The Given Value was not found in the List.... Please try again\n");
        	return head;
    	}
	}
}

NODE* insertFront(NODE* head, int x){
	NODE *p = (NODE*) malloc(sizeof(NODE));
	if(head == NULL) {
    	p->info = x;#include <stdio.h>
#include <stdlib.h>
struct node {
	int info;
	struct node *next;
};
typedef struct node NODE;

NODE* insertBefore(NODE* head, int x, int val) {
	if(head == NULL) {
    	printf("NO LIST CREATED \n");
    	return NULL;
	}
	else {
    	NODE* p = head, *q;
    	while(p->info != x || p->next != NULL) {
            	q = p;
            	p = p->next;
    	}
    	if(p->info == x) {
        	NODE* a = (NODE*) malloc(sizeof(NODE));
        	a->info = x;
        	a->next = q->next;
        	a->next = p;
        	return head;
    	}else {
        	printf("The Given Value was not found in the List.... Please try again\n");
        	return head;
    	}
	}
}

NODE* insertFront(NODE* head, int x){
	NODE *p = (NODE*) malloc(sizeof(NODE));
	if(head == NULL) {
    	p->info = x;
    	p->next = NULL;
    	return p;
	}
	p->info = x;
	p->next = head;
	return p;
}
NODE* insertEnd(NODE* head, int x){
	NODE *q = (NODE*) malloc(sizeof(NODE));
	NODE *p = head;
	if(p == NULL) {
    	q->info = x;
    	q->next = NULL;
    	return q;
	}
	while(p->next != NULL) {
    	p = p->next;
	}
	p->next = q;
	q->info = x;
	q->next = NULL;
	return head;
}
NODE* deleteStart(NODE* head){
	NODE *p = head;
	if(p == NULL) {
    	printf("There Are No elements in the List\n");
    	return NULL;
	}
	if(p->next == NULL) {
    	printf("The Deleted Element is %d \n",p->info);
    	free(p);
    	return NULL;
	}
	head = p->next;
	//p->next = NULL;
	printf("The Deleted Element is %d \n",p->info);
	free(p);
	return head;
}
NODE* deleteEnd(NODE* head){
	NODE *p = head, *q;
	if(p == NULL) {
    	printf("There Are No elments in the List\n");
    	return head;
	}
	while(p->next != NULL) {
    	q->next = p;
    	p = p->next;
	}
	q->next = NULL;
	printf("The Deleted Element is %d \n",p->info);
	free(p);
	return head;
}
NODE* deleteX(NODE* head, int x){
	NODE *p = head, *q;
	int i = 0;
	if(head == NULL) {
    	printf("No Elements to Delete\n");
    	return head;
	}else {
    	if(p->info == x) {
        	printf("Element is deleted is %d\n",p->info);
        	head = p->next;
        	free(p);
        	return head;
    	}else {
        	while (p->info != x) {
            	q = p;
            	p = p->next;
            	if (p->next == NULL) {
                	i = 1;
            	}
        	}
        	if (i) {
            	printf("NO %d present in the list", x);
        	} else {
            	q->next = p->next;
            	printf("Element is deleted is %d\n", p->info);
            	free(p);
        	}
    	}
    	return head;
	}
}
NODE* insertX(NODE* head, int val, int x){
	NODE *p = head;
	NODE *q = (NODE *) malloc(sizeof(NODE));
	if(head == NULL) {
    	printf("NO Elements present in the list\n");
    	free(q);
    	return head;
	}else {
    	while(p->info != x || p->next != NULL) {
        	p = p->next;
    	}
    	if(p->info == x) {
        	q->next = p->next;
        	q->info = val;
        	p->next = q;
        	return head;
    	}
	}
}

void display(NODE* head) {
	NODE *p = head;
	if(p == NULL) {
    	printf("No Elements in List\n");
	}else {
    	while (p->next != NULL) {
        	printf("%d\n", p->info);
        	p = p->next;
    	}
    	printf("%d\n", p->info);
	}
}

NODE* createList(NODE* head, int x) {
	return insertFront(head, x);
}
void main() {
	NODE *head = NULL;
	int n, val, x;
	while(1) {
    	printf("Welcome to Linked List\n");
    	printf("Select a operation\n");
    	printf("1.INSERT AT START\n2.INSERT AT END\n3.INSERT AFTER X\n4.DELETE AT START\n5.DELETE AT END\n6.DELETE X\n7.DISPLAY LIST\n8.CREATE LIST\n9.EXIT\n10.INSERT BEFORE X");
    	scanf("%d", &n);
    	switch (n) {
        	case 1:
            	printf("Enter the element\n");
            	scanf("%d", &val);
            	head = insertFront(head, val);
            	printf("%d\t",head->info);
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
            	head = deleteX(head, x);
            	break;
        	case 7:
            	display(head);
            	break;
        	case 9:
            	return;
        	case 8:
            	printf("Enter The Value of x :");
            	scanf("%d",&x);
            	head = createList(head, x);
            	break;
        	case 10:
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

    	p->next = NULL;
    	return p;
	}
	p->info = x;
	p->next = head;
	return p;
}
NODE* insertEnd(NODE* head, int x){
	NODE *q = (NODE*) malloc(sizeof(NODE));
	NODE *p = head;
	if(p == NULL) {
    	q->info = x;
    	q->next = NULL;
    	return q;
	}
	while(p->next != NULL) {
    	p = p->next;
	}
	p->next = q;
	q->info = x;
	q->next = NULL;
	return head;
}
NODE* deleteStart(NODE* head){
	NODE *p = head;
	if(p == NULL) {
    	printf("There Are No elements in the List\n");
    	return NULL;
	}
	if(p->next == NULL) {
    	printf("The Deleted Element is %d \n",p->info);
    	free(p);
    	return NULL;
	}
	head = p->next;
	//p->next = NULL;
	printf("The Deleted Element is %d \n",p->info);
	free(p);
	return head;
}
NODE* deleteEnd(NODE* head){
	NODE *p = head, *q;
	if(p == NULL) {
    	printf("There Are No elments in the List\n");
    	return head;
	}
	while(p->next != NULL) {
    	q->next = p;
    	p = p->next;
	}
	q->next = NULL;
	printf("The Deleted Element is %d \n",p->info);
	free(p);
	return head;
}
NODE* deleteX(NODE* head, int x){
	NODE *p = head, *q;
	int i = 0;
	if(head == NULL) {
    	printf("No Elements to Delete\n");
    	return head;
	}else {
    	if(p->info == x) {
        	printf("Element is deleted is %d\n",p->info);
        	head = p->next;
        	free(p);
        	return head;
    	}else {
        	while (p->info != x) {
            	q = p;
            	p = p->next;
            	if (p->next == NULL) {
                	i = 1;
            	}
        	}
        	if (i) {
            	printf("NO %d present in the list", x);
        	} else {
            	q->next = p->next;
            	printf("Element is deleted is %d\n", p->info);
            	free(p);
        	}
    	}
    	return head;
	}
}
NODE* insertX(NODE* head, int val, int x){
	NODE *p = head;
	NODE *q = (NODE *) malloc(sizeof(NODE));
	if(head == NULL) {
    	printf("NO Elements present in the list\n");
    	free(q);
    	return head;
	}else {
    	while(p->info != x || p->next != NULL) {
        	p = p->next;
    	}
    	if(p->info == x) {
        	q->next = p->next;
        	q->info = val;
        	p->next = q;
        	return head;
    	}
	}
}

void display(NODE* head) {
	NODE *p = head;
	if(p == NULL) {
    	printf("No Elements in List\n");
	}else {
    	while (p->next != NULL) {
        	printf("%d\n", p->info);
        	p = p->next;
    	}
    	printf("%d\n", p->info);
	}
}

NODE* createList(NODE* head, int x) {
	return insertFront(head, x);
}
void main() {
	NODE *head = NULL;
	int n, val, x;
	while(1) {
    	printf("Welcome to Linked List\n");
    	printf("Select a operation\n");
    	printf("1.INSERT AT START\n2.INSERT AT END\n3.INSERT AFTER X\n4.DELETE AT START\n5.DELETE AT END\n6.DELETE X\n7.DISPLAY LIST\n8.CREATE LIST\n9.EXIT\n10.INSERT BEFORE X");
    	scanf("%d", &n);
    	switch (n) {
        	case 1:
            	printf("Enter the element\n");
            	scanf("%d", &val);
            	head = insertFront(head, val);
            	printf("%d\t",head->info);
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
            	head = deleteX(head, x);
            	break;
        	case 7:
            	display(head);
            	break;
        	case 9:
            	return;
        	case 8:
            	printf("Enter The Value of x :");
            	scanf("%d",&x);
            	head = createList(head, x);
            	break;
        	case 10:
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

