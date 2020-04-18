#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define SIZE 30

void push(char);
char pop();
int preced(char);

char stack[SIZE], postfix[SIZE], infix[SIZE];
int top = -1;

int main()
{
	char ch;
	int i, k, p = 0;
	for(i=0; i<SIZE; i++)
	{
		stack[i] = '\0';
	}
	printf("\nEnter an prefix expression: ");
	scanf("%s",infix);
	for(i=0; infix[i] != '\0'; i++)
	{
		ch = infix[i];
		
		if (isalnum(ch))
		{
			postfix[p++] = ch;
		}
		else if (ch == '(')
		{
			push(ch);
		}
		else if (ch == ')')
		{
			while(stack[top] != '(')
			{
				postfix[p++] = pop();
			}
			pop();
		}
		else if (ch == '/' || ch == '*' || ch == '+' || ch == '-')
		{
			if (preced(ch) > preced(stack[top]))
			{
				push(ch);
			}
			else
			{
				while (preced(ch) <= preced(stack[top]))
				{
					postfix[p++] = pop();
				}
						
			}
		}		
	}
	postfix[p] = '\0';
	while(top > -1)
		postfix[p++] = pop();
		

	printf("\nThe postfix expression is: %s\n",postfix);
	
	return 0;
}
void push(char el)
{
	if (top < SIZE-1)
	{
		stack[++top] = el;
	}
	else
	{
		printf("\nError! Stack is full.\n");
		exit(-1);
	}
}
char pop()
{
	char ch;
	if (top > -1)
	{
		ch = stack[top];
		stack[top--] = '\0';
	
		return ch;
	}
	else
	{
		printf("\nError! Stack is empty.\n");
		exit(-1);
	}
}
int preced(char ch)
{
	if(ch == '(' || ch == ')')
		return 0;
	else if (ch == '+' || ch == '-')
		return 1;
	else if (ch== '/' || ch == '*')
		return 2; 
}
