#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
# define MAX 20

struct stack {
	int top;
	int stack[MAX];
};
typedef struct stack STACK;
char str[MAX]; 

 
char pop(STACK *stack1)
{
      return stack1->stack[stack1->top--];
}
 
void push(char ch,STACK *stack1)
{
      stack1->stack[++stack1->top] = ch;
}
 
void postfix_to_infix(char expression[])
{
      STACK stack2;
      stack2.top = -1;
      int count, length;
      char element, operator;
      length = strlen(expression);
      for(count = 0; count < MAX; count++)
      {
            stack2.stack[count] = 0;
      }
      printf("\nInfix Expression:\t");
      printf("%c", expression[0]);
      for(count = 1; count < length; count++)
      {
            if(expression[count] == '-' || expression[count] == '/' || expression[count] == '*'|| expression[count] == '+')
            {
                  element = pop(&stack2);
                  operator = expression[count];
                  printf(" %c %c", operator, element);
            }
            else
            {
                  push(expression[count],&stack2);
            }
      }
      printf("%c", expression[stack2.top--]);
}
 
int main()
{
      char postfix_expression[50];
      printf("\nEnter Postfix Expression:\t");
      scanf("%s", postfix_expression);
      postfix_to_infix(postfix_expression);
      printf("\n");
      return 0;
}
