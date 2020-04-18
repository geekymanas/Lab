//
// Created by manasabhilash on 8/17/18.
//

#include <stdio.h>
#define queueSize 100

struct queue {
	int arr[queueSize];
	int front, rear;
};
typedef struct queue QUEUE;

void push(QUEUE *qu1, int val) {
	qu1->arr[++qu1->rear] = val;
}

void pop(QUEUE *qu1, QUEUE *qu2) {
	if (qu1->rear == -1) {
    	printf("No Elements in stack\n");
	} else {
    	while (qu1->front != qu1->rear) {
        	qu2->arr[++qu2->rear] = qu1->arr[qu1->front++];
    	}
    	printf("The Deleted Element is %d\n", qu1->arr[qu1->rear--]);
    	qu1->rear = -1;
    	qu1->front = 0;
    	while (qu2->rear != -1) {
        	qu1->arr[++qu1->rear] = qu2->arr[qu2->rear--];
    	}
	}
}

void display(QUEUE *qu1) {
	if (qu1->rear == -1) {
    	printf("No Elements in the stack\n");
	} else {
    	while (qu1->rear != -1) {
        	printf("%d\n", qu1->arr[qu1->rear--]);
    	}
	}
}

int main() {
	QUEUE qu1, qu2;
	qu1.front = 0;
	qu1.rear = -1;
	qu2.front = 0;
	qu2.rear = -1;
	int n, val;
	while (1) {
    	printf("Welcome to stack using queue\n");
    	printf("1.PUSH ELEMENT \n2.POP ELEMENT\n3.DISPLAY STACK\n4.EXIT\n");
    	scanf("%d", &n);
    	switch (n) {
        	case 1:
            	scanf("%d", &val);
            	push(&qu1, val);
            	break;
        	case 2:
            	pop(&qu1, &qu2);
            	break;
        	case 3:
            	display(&qu1);
            	break;
        	case 4:
            	return 0;
        	default:
            	break;
    	}
	}
}
