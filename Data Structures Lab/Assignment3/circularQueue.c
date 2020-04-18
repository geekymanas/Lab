#include <stdio.h>
#define size 100
void insert(int[], int);
void delete(int[]);
void display(int[]);

int front = -1, rear = -1;

int main() {
 int n, ch;
 int queue[size];
 do{
   printf("1.Insert \n2.Delete \n3.Display\n4.Exit\n");
   scanf("%d",&ch);
   switch(ch) {
    case 1:
       printf("Enter a number");
       scanf("%d",&n);
       insert(queue, n);
       break;
   case 2:
       delete(queue);
       break;
   case 3:
       display(queue);
       break;
   case 4:
       return;
   default:
       break;
   }
 }while(ch != 0);
}

void insert(int queue[], int i) {
  if((front == 0 && rear == size-1) || (front == rear+1)) {
     printf("Queue is Full");
     return;
  }else if(rear == -1) {
     rear++;
     front++;
   }else if(rear == size-1 && front > 0) {
     rear = 0;
     }else {
       rear++;
      }
      queue[rear] = i;
}

void display(int queue[]) {
   int i;
   printf("\n");
   if(front > rear) {
    for(i = front;i < size;i++) {
      printf("%d",queue[i]);
    }
    for(i = 0;i<=rear;i++)
    {
     printf("%d",queue[i]);
    }
   }else {
     for(i = front;i < rear;i++) { 
      printf("%d",queue[i]);
     }
 }
}

void delete(int queue[]) { 
 if(front == -1) {
  printf("Queue is empty");
 }else if(front == rear) {
   printf("%d deleted",queue[front]);
   front = -1;
   rear = -1;
  }else {
    printf("%d deleted",queue[front]);
    front++;
}
}