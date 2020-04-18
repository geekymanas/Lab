#define SIZE 50
#include <ctype.h>
#include <stdio.h>

struct stack {
    char s[SIZE];
    int top;
};
typedef struct stack STACK;
void push(char elem, STACK *stack1)
{
    stack1->s[++stack1->top]=elem;
}

char pop(STACK *stack1)
{
    return(stack1->s[stack1->top--]);
}

int pr(char elem)
{
    switch(elem)
    {
        case '#': return 0;
        case '(': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 3;
    }
}

int main()
{
    STACK stack1;
    stack1.top = -1;
    char infix[50],prefix[50],ch,elem;
    int i=0,k=0;
    printf("\n\nRead the Infix Expression ? ");
    scanf("%s",infix);
    push('#', &stack1);
    while( (ch=infix[i++]) != '\0')
    {
        if( ch == '(') push(ch, &stack1);
        else
        if(isalnum(ch)) prefix[k++]=ch;
        else
        if( ch == ')')
        {
            while(stack1.s[stack1.top] != '(')
                prefix[k++]=pop(&stack1);
            elem=pop(&stack1);
        }
        else
        {
            while( pr(stack1.s[stack1.top]) >= pr(ch) )
                prefix[k++]=pop(&stack1);
            push(ch, &stack1);
        }
    }
    while( stack1.s[stack1.top] != '#')
        prefix[k++]=pop(&stack1);
    prefix[k]='\0';
    printf("\n\nGiven Infix Expn: %s  Postfix Expn: %s\n",infix,prefix);
}
