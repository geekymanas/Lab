#define SIZE 100
struct node {
    int info;
    struct node* next;
};
typedef struct node NODE;    

NODE* createNode(int x) {
    NODE *q = (NODE*) malloc(sizeof(NODE));
    q->info = x;
    q->next = NULL;
    return q;
}

NODE* push(NODE* s, int x) {
    NODE* p = s, *q;
    if(s == NULL) {
   	 NODE* q = createNode(x);
   	 return q;
    }
    while(p->next != NULL) {
   	 p = p->next;
    }
    p->next = q;
    return s;
}

void pop(NODE* s) {
    NODE *p = s, *q;
    if(s == NULL) {
   	 printf("NO elements to pop");
   	 return;
    }else {
    while(p->next != NULL) {
   	 q = p;
   	 p = p->next;
    }
    printf("The Removed Element is %d ",p->info);
    q->next = NULL;
    free(p);
    }
}



void display(NODE* s) {
    NODE* q = s;
    if(q == NULL) {
   	 printf("No elements\n");
    }else {
   	 if(q->next == NULL) {
   		 printf("%d",q->info);
   	 }
   	 else{
   		 while(q->next != NULL) {
   			 printf("%d\n",q->info);
   			 q = q->next;
   		 }
   	 }    
    }
}    
int main() {
    NODE* stack = NULL;
    int n, x, val;
    printf("Welcome to Stack using linked list\n");
    while(1) {
   	 printf("1.Push Element into Stack\n2.Pop element from stack\n3.Display\n4.Exit");
   	 scanf("%d",&n);
   	 switch(n) {
   		 case 1:
   			 printf("Enter The Value to be pushed onto stack\n");
   			 scanf("%d",&val);
   			 stack = push(stack, val);
   			 break;
   		 case 2:
   			 pop(stack);    
   			 break;
   		 case 3:
   			 display(stack);
   			 break;
   		 case 4:
   			 return 1;
   			 break;    
   		 default:
   			 printf("Choose valid option");
   			 break;
   	 }
   	 }
 
}

