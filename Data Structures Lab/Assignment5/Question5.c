int i = 0;
struct Node {
	int info;
	struct Node* next;
	struct Node* prev;
};
typedef struct Node NODE;

NODE* createNode(int x) {
	NODE* p = (NODE*) malloc(sizeof(NODE));
	p->next = NULL;
	p->prev = NULL;
	p->info = x;
	return p;
}

NODE* insertFront(NODE* head, int x) {
  NODE* p = createNode(x);
  if(head != NULL) {
  	p->next = head;
  	head->prev = p;
  }
  return p;
}

NODE* insertEnd(NODE* head, int x) {
 NODE* p = createNode(x);
 if(head == NULL) {
 	return p;
 }
 NODE* end = head;
 while(end->next != NULL) {
 	end = end->next;
 }
 p->prev = end;
 end->next = p;
 return head;
}

NODE* insertX(NODE* head, int x, int val) {
   if(head != NULL) {
   	NODE *p = createNode(x);
   	NODE *q = head;
   	while (q->next != NULL && q->info != val) {
       	q = q->next;
   	}
   	if (q->info == val) {
       	p->info = x;
       	p->next = q->next;
       	p->prev = q;
       	(q->next)->prev = p;
       	q->next = p;
   	} else {
       	printf("No element %d present in List\n", val);
       	free(p);
   	}
   	return head;
   }
}

NODE* insertBefore(NODE *head, int x, int val) {
  if(head == NULL) {
      head = createNode(x);
    	return head;
  }
  NODE* p = createNode(x);
  NODE* q = head;
  while(q->next != NULL && q->info != val) {
	 q = q->next;
  }
  if(q->info == val) {
 	p->info = x;
 	(q->prev)->next = p;
 	p->prev = (q->prev);
 	p->next = q;
 	return head;
  }else {
	printf("No element %d present in List\n",val);
	return head;
  }
}

void display(NODE* head) {
  if(head == NULL) {
	printf("No Elements in List\n");
  }
  NODE* p  = head;
  while(p->next != NULL) {
	printf("%d\n",p->info);
	p = p->next;
  }
 printf("%d\n",p->info);
}

NODE* deleteStart(NODE* head) {
  NODE* p = head;
  if(p == NULL) {
	printf("No elements present in the list\n");
	return head;
  }
  if(head->next == NULL) {
 	free(p);
 	return NULL;
  }
  else {
	head = p->next;
	head->prev = NULL;
	return head;
  }
}

NODE* deleteEnd(NODE* head) {
  NODE* p = head->prev;
  if(head->next == NULL) {
  }
  (p->prev)->next = NULL;
  free(p);
  return head;
}

int main() {
  NODE* head;
  int n, x, val;
  while(1) {
  printf("----Main-Menu----\n");
  printf("1.Create List\n2.Insert at start\n3.Insert at end\n4.Insert after X\n5.Insert before X\n6.Delete at start\n7.Delete at end\n8.Delete X\n9.Display List\n10.Exit\nEnter an option: ");
  scanf("%d",&n);
  switch (n) {
  	case 1:
      	printf("Enter The Element : ");
      	scanf("%d",&x);
      	head = createNode(x);
      	break;
  	case 2:
      	printf("Enter the element: ");
      	scanf("%d",&x);
      	head = insertFront(head, x);
      	break;
  	case 3:
      	printf("Enter the element: ");
      	scanf("%d",&x);
      	head = insertEnd(head, x);
      	break;
  	case 4:
      	printf("Enter the element after which insertion to be made");
      	scanf("%d",&val);
      	printf("Enter the element:");
      	scanf("%d",&x);
      	head = insertX(head, x, val);
      	break;
  	case 5:
      	printf("Enter the element before which insertion to be made");
      	scanf("%d",&val);
      	printf("Enter the element");
      	scanf("%d",&x);
      	head = insertBefore(head, x, val);
      	break;
  	case 6:
      	head = deleteStart(head);
      	break;
  	case 7:
      	deleteEnd(head);
      	break;
  	case 8:
      	printf("Enter element to be deleted\n");
   	   scanf("%d",&x);
   	//   deleteX(head, x);
      	break;
  	case 9:
      	display(head);
      	break;
  	case 10:
      	return 1;
  	default :
      	break;
  }
 }
}

