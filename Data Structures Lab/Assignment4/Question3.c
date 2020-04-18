#include<stdio.h>
#define maxsize 9
#define n 3

int m,count;

typedef struct stack{
    int arr[maxsize];
    int top[n];
    int base[n+1];
} STACK;
STACK* s;

void push(int x);
void pop();
void display();

int main()
{
    int i,k=0,c,x;
    printf("Welcome to n stacks in array\n");
    STACK s1;
    s=&s1;
    for(i=0;i<maxsize;i+=maxsize/n)
    {
   	 s->base[k]=i;
   	 s->top[k++]=i-1;
    }
    s->base[k]=maxsize;
    count=0;
    while(1)
    {    
   	 printf("\nEnter the stack number to be used\n");
   	 scanf("%d",&m);
   	 if(m>0 && m<=n)
   	 {
   		 printf("\n1.insert element onto stack\n");
   		 printf("2.pop element from stack\n");
   		 printf("3.Enter 3 to display stack\n");
   		 printf("4.Enter 4 to exit\n");
   		 scanf("%d",&c);
   		 if(c==1)
   		 {
   			 printf("\nEnter the element you want to insert : ");
   			 scanf("%d",&x);
   			 push(x);
   		 }
   		 else if(c==2)
   			 pop();
   		 else if(c==3)
   			 display();
   		 else if(c==4)
   		 {
   			 printf("Bye\n");
   			 break;
   		 }
   		 else
   			 printf("Enter a valid option\n");
   	 }
   	 else
   		 printf("Invalid stack number\n");
    }
    return 0;
}

void push(int x)
{
    int i=1,j;
    if(count==maxsize)
    {
   	 printf("\nGlobal overflow\n");
   	 return;
    }
    if(s->top[m-1]!=s->base[m]-1)
   	 s->arr[++(s->top[m-1])]=x;
    else
    {    
   	 while(((i+m)!=n+1) && (s->top[i+m-1]==((s->base[i+m])-1)))
   		 i++;
   	 if(i+m==n+1)
   	 {
   		 i=1;
   		 while(s->top[m-i-1]==s->base[m-i]-1)
   			 i++;
   		 for(j=s->base[m-i];j<=s->top[m-1];j++)
   			 s->arr[j-1]=s->arr[j];
   		 s->arr[s->top[m-1]]=x;
   		 for(j=1;j<=i;j++)
   		 {
   			 (s->base[m-j])--;
   			 if(j!=1)
   				 (s->top[m-j])--;
   		 }
   	 }
   	 else
   	 {
   		 for(j=s->top[i+m-1];j>=s->base[m];j--)
   			 s->arr[j+1]=s->arr[j];
   		 s->arr[++(s->top[m-1])]=x;
   		 for(j=1;j<=i;j++)
   		 {
   			 (s->top[m+j-1])++;
   			 (s->base[m+j-1])++;
   		 }
   	 }
    }
    count++;
}

void pop()
{
    if(count==0)
   	 printf("Global underflow\n");
    else if(s->top[m-1]==s->base[m-1]-1)
   	 printf("Local underflow\n");
    else
    {
   	 printf("\n%d",s->arr[(s->top[m-1])--]);
   	 printf("\nElement deleted\n");
    }
    count--;
}

void display()
{
    if(count==0)
   	 printf("\nStack is empty\n");
    else if(s->top[m-1]==s->base[m-1]-1)
   	 printf("\nThe target stack is empty\n");
    else
    {
   	 printf("Elements of the stack are:\n");
   	 for(int i=s->base[m-1];i<=s->top[m-1];i++)
   		 printf("%d\t",s->arr[i]);
   	 printf("\n");
    }
}

