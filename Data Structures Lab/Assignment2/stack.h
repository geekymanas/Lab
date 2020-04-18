//
// Created by manasabhilash on 7/31/18.
//

#ifndef UNTITLED_STACK_H
#define UNTITLED_STACK_H

#endif //UNTITLED_STACK_H
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

void pop(STACK *stack1) {
    if(stack1->top == -1) {
        printf("Underflow");
    }else {
        printf("The number popped is %d ",stack1->arr[stack1->top--]);
    }
}

void display(STACK *stack1) {
    int point  = stack1->top;
    while(point != -1) {
        printf("%d\n",stack1->arr[point--]);
    }
}

int checkAplhabet(int c) {
    return ((c >= 'a' && c <= 'z') ||(c>='A' && c<= 'Z') || (c >= 0 && c <= 9));
}

int checkOperator(char c) {
    switch(c) {
        case '*':
        case '%':
        case '+':
        case '-':
        case '/':
        case '^':
            return 1;
        default :return 0;
    }
}

