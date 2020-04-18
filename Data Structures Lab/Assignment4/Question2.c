//
// Created by manasabhilash on 8/17/18.
//

#include <stdio.h>
#define stackSize 100

struct stack {
	int arr[stackSize];
	int top;
};
typedef struct stack STACK;

void push(int x, STACK *stack1) {
	if(stack1->top+1>=stackSize) {
    	printf("Stack overflow");
	}else {
    	stack1->arr[++stack1->top] = x;
	}
}

int pop(STACK *stack1) {
	//if(stack1->top == -1) {
	//  printf("Underflow");
	//}else {
	return stack1->arr[stack1->top--];
	//printf("The number popped is %d ",stack1->arr[stack1->top--]);
	//}
}

void display(STACK *stack1) {
	if(stack1->top == -1) {
    	printf("No Elements present\n");
	}else {
    	int point = stack1->top;
    	while (point != -1) {
        	printf("%d\n", stack1->arr[point--]);
    	}
	}
}

void enqueue(STACK *stack1, int val) {
	if(stack1->top+1 == stackSize) {
    	printf("Queue out of space\n");
	}else {
    	stack1->arr[++stack1->top] = val;
	}
}

void dequeue(STACK *stack1, STACK *stack2) {
	if(stack1->top == -1) {
    	printf("No Elements present\n");
	}else {
    	while(stack1->top != -1) {
            	printf("%d\n",stack1->top);
            	stack2->arr[++stack2->top] = pop(stack1);
    	}
    	printf("The Element dequed is %d \n",pop(stack2));
    	while(stack2->top != -1) {
        	printf("%d\n",stack2->top);
        	stack1->arr[++stack1->top] = pop(stack2);
    	}
	}
}

int main() {
	STACK stack1, stack2;
	stack1.top = -1;
	stack2.top = -1;
	int n, val = 0;
	while(1) {
    	printf("Welcome to Queue using Stack\n");
    	printf("1.Insert Element into the Queue\n2.Delete an Element from the Queue\n3.Display the contents of the Queue\n4.Exit\n");
    	scanf("%d", &n);
    	switch (n) {
        	case 1:
            	printf("Enter the Element\n");
            	scanf("%d",&val);
            	enqueue(&stack1, val);
            	break;
        	case 2:
            	dequeue(&stack1, &stack2);
            	break;
        	case 3:
            	display(&stack1);
            	break;
        	case 4:
            	return 0;
        	default:
            	break;
    	}
	}
}

