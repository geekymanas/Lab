#include<stdio.h>
#define maxsize 9
#define n 3
int count,m;

typedef struct queue{
    int arr[maxsize];
    int front[n];
    int rear[n];
} QUEUE;
QUEUE* q;

void push(int x)
{
    if(count==maxsize)
   	 printf("\nGLOBAL OVERFLOW\n");
    else if(((q->rear[(m-1)]+1)%n)!=(q->front[m%n]))
   	 q->arr[++(q->rear[m-1])]=x;
    else
    {
   	 int i=1,j;
   	 while(q->rear[(m+i-1)%n]==q->front[(m+i)%n]-1)
   		 i++;
   	 for(j=q->rear[(m+i-1)%n];j>=q->front[m%n];j--)
   		 q->arr[(j+1)%n]=q->arr[j%n];
   	 for(j=1;j<=i;j++)
   	 {
   		 q->rear[m-j+1]++;
   		 q->front[m-j]++;
   	 }
   	 q->arr[q->rear[m-1]]=x;
    }
    count++;
}

void pop()
{
    if(count==0)
   	 printf("\nGLOBAL UNDERFLOW\n");
    else if((q->rear[m-1]-q->front[m-1]+1)==0)
   	 printf("The target queue is empty\n");
    else
    {
   	 printf("\n%d\n",q->arr[(q->rear[m-1])--]);
   	 printf("Element deleted\n");
    }
    count--;
}

void display()
{
    int i;
    if(count==0)
   	 printf("\nQueue is empty\n");
    else if((q->rear[m-1]-q->front[m-1]+1)==0)
   	 printf("The target queue is empty\n");
    else
    {
   	 printf("\nThe elements in the queue are:\n");
   	 if(q->front[m-1]<=q->rear[m-1])
   	 {
   		 for(int i=q->front[m-1];i<=q->rear[m-1];i++)
   			 printf("%d\t",q->arr[i]);
   		 printf("\n");
   	 }
   	 else
   	 {
   		 for(i=q->front[m-1];i<maxsize;i++)
   			 printf("%d\t",q->arr[i]);
   		 for(i=0;i<=q->rear[m-1];i++)
   			 printf("%d\t",q->arr[i]);
   		 printf("\n");
   	 }
    }
}

int main()
{
    int i,k=0,c,x;
    printf("Welcome to the menu driven program to inset n queues in a single array\n");
    QUEUE q1;
    q=&q1;
    for(i=0;i<maxsize;i+=maxsize/n)
    {
   	 q->front[k]=i;
   	 q->rear[k++]=i-1;
    }
    count=0;
    while(1)
    {    
   	 printf("\nEnter the queue which you want to access. Numbering initialised from 1\n");
   	 scanf("%d",&m);
   	 if(m>0 && m<=n)
   	 {
   		 printf("\nEnter 1 to insert element into queue\n");
   		 printf("Enter 2 to delete element from queue\n");
   		 printf("Enter 3 to display elements of the queue\n");
   		 printf("Enter 4 to exit\n");
   		 scanf("%d",&c);
   		 if(c==1)
   		 {
   			 printf("\nEnter the element you want to insert ");
   			 scanf("%d",&x);
   			 push(x);
   		 }
   		 else if(c==2)
   			 pop();
   		 else if(c==3)
   			 display();
   		 else if(c==4)
   		 {
   			 printf("Exiting\n");
   			 break;
   		 }
   		 else
   			 printf("Enter a choice between 1 to 4\n");
   	 }
   	 else
   		 printf("Incorrect queue number. Enter correct value\n");
    }
    return 0;
}

