//
// Created by manasabhilash on 8/6/18.
//
#define stackSize 100
#include <stdio.h>
struct stack {
    int arr[stackSize];
    int top1;
    int top2;
};
typedef struct stack STACK;

void push(STACK *stack1, int op, int val) {
    if(op == 1) {
        if(stack1->top1 + 1 < stack1->top2) {
            stack1->arr[++stack1->top1] = val;
        }else {
            printf("Local Overflow of stack1");
        }
    }else if(op == 2) {
        if(stack1->top2 - 1 > stack1->top1) {
            stack1->arr[--stack1->top2] = val;
        }else {
            printf("Local Overflow of stack2");
        }
    }
}

void display(STACK *stack1, int op) {
    if (op == 1) {
        int top = stack1->top1;
        while (1) {
            if (top == -1) {
                printf("Came HEre");
                break;
            }
            printf("hERE");
            int val = stack1->arr[top];
            --top;
            printf("%d\n", val);
        }
    } else if (op == 2) {
        int top = stack1->top2;
        while (1) {
            if (top == stackSize) {
                break;
            }
            int val = stack1->arr[top];
            ++top;
            printf("%d\n", val);
        }
    }
    if(stack1->top1 + 1 == stack1->top2) {
        printf("Global Overflow");
    }
}

int pop(STACK *stack1, int op) {
    if(op == 1) {
        if(stack1->top1 == -1) {
            printf("Underflow !! \nTerminating....\nGoodBye..\n");
        }else {
            int val = stack1->arr[stack1->top1--];
            printf("The value popped is %d\n",val);

        }
    }else if(op == 2) {
        if(stack1->top2 == stackSize) {
            printf("Underflow !! \nTerminating....\nGoodBye..\n");
        }else {
            int val = stack1->arr[stack1->top2++];
            printf("The value popped is %d\n",val);
        }
    }
}
int main() {
    STACK *stack1;
    stack1->top1 = -1;
    stack1->top2 = stackSize;
    int n = 0, op = 0, exit = 0, val;
    while(1) {
        printf("Select the stack \n1.Stack1\n2.Stack2\n");
        scanf("%d",&n);
        printf("Select the operations you want to perform\n");
        printf("1.PUSH ELEMENT \n2.POP ELEMENT\n3.DISPLAY STACK\n4.EXIT\n");
        scanf("%d",&op);
        switch(op) {
            case 1:
                scanf("%d",&val);
                push(stack1, n, val);
                break;
            case 2:
                 pop(stack1, n);
                break;
            case 3:
                display(stack1, n);
                break;
            case 4:
                exit = 1;
            default:
                exit = 1;
        }
        if(exit) {
            exit = 0;
            break;
        }
    }
}