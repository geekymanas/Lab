#include <stdio.h>
#include "stack.h"
int main () {
    int sit = 0;
    STACK stack;
    stack.top = -1;
    while(1) {
        int n, x;
        printf("1.PUSH FUNCTION\n2.POP FUNCTION\n3.DISPLAY FUNCTION\n4.EXIT\n");
        scanf("%d",&n);
        switch(n) {
            case 1:
                printf("Enter The Number to Be Pushed onto the Stack\n");
                scanf("%d",&x);
                push(x, &stack);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                sit = 1;
            default:
                break;
        }
        if(sit == 1) {
            sit = 0;
            break;
        }
    }
}
