#include <stdio.h>
#define queueSize 100
struct queue {
 int arr[queueSize];
 int front;
 int rear;
};
typedef struct queue QUEUE;

int isFull(QUEUE* qu5) {
 if(qu5->rear == queueSize-1) 
   return 1;
 else
  return 0;
}

void enqueue(QUEUE* qu, int x) {
 if(isFull(qu))
  return;
 qu->rear = qu->rear + 1 ;
 qu->arr[qu->rear] = x;
}

void display(QUEUE* qu) {
 int front = qu->front, rear = qu->rear;
 printf("The Elements of Queue are\n");
 while(front != rear+1) {
  printf("%d\n",qu->arr[front]);
  front++;
 }
}
void dequeue(QUEUE *qu) {
 if(qu->rear != -1) {
 int x = qu->arr[qu->front];
 qu->front++;
 if(qu-> rear == qu->front && qu->front != 0) {
   qu->rear = -1;
   qu->front = 0;
  }
  printf("The Value Deleted is %d ",x);
}else {
 printf("No elements left");
  
}
}
int main() {
 QUEUE qu1;
 qu1.front = 0;
 qu1.rear = -1;
 int n;
 while(1) {
 printf("Select an operation to be performed on Queue\n");
 printf("1.Insert Element into the Queue\n2.Delete an Element from the Queue\n3.Display the contents of the Queue\n4.Exit\n");
 scanf("%d",&n);
 int val;
 switch(n) {
  case 1:
    printf("Enter value to be inserted in the queue\n");
    scanf("%d",&val);
    enqueue(&qu1, val);
    break;
  case 2:
    dequeue(&qu1);
    break;
  case 3:
    display(&qu1);
    break;
  case 4:
    printf("Terminating process.....\nExiting....\nBye\n");
    return;
  default: 
    break;
 }
}
}
