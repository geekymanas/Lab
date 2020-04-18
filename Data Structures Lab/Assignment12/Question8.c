#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};
typedef struct node NODE;

NODE* createNode(int info){
    NODE *p = (NODE*) malloc(sizeof(NODE));
    p->info = info;
    p->next = NULL;
    return p;
}

NODE* createList(NODE *head, int n, int arr[]){
    int info, i = 0;
    NODE *newNode;
    if(head == NULL){
   	 printf("Enter Element : ");
   	 scanf("%d",&info);
   	 arr[i] = info;
   	 i++;
   	 head = createNode(info);
   	 n--;
    }
    NODE *p = head;
    while(n--){
   	 printf("Enter The Element : ");
   	 scanf("%d",&info);
   	 arr[i] = info;
   	 i++;
   	 while(p->next != NULL){
   		 p = p->next;
   	 }
   	 newNode = createNode(info);
   	 p->next = newNode;
    }
    return head;
}

void display(NODE *head){
    NODE *p = head;
    while(p != NULL){
   	 printf("%d",p->info);
   	 p = p->next;
    }
}

int lis( int arr[], int n ) {
    
	int result = 0;
	int lis[n];
	for (int i = 0; i < n; i++ )
    	lis[i] = 1;
	for (int i = 1; i < n; i++ )
    	for (int j = 0; j < i; j++ )
        	if ( arr[i] > arr[j] &&
             	lis[i] < lis[j] + 1)
        	lis[i] = lis[j] + 1;
	for (int i = 0; i < n; i++ )
    	if (result < lis[i])
        	result = lis[i];
 
	return result;
}
int minimumNumberOfDeletions(int arr[],int n) {
    
	int len = lis(arr, n);
	return (n - len);
}

int getNumberofOrderedPairs(int arr[], int n){
    int i, count = 0;
    if(1){
   	 for(i = 0;i < n-1;i+=2){
   		 if(arr[i] < arr[i+1]) {
   			 count+=2;
   		 }
   	 }
    }
    printf("%d\n",count);
    return count;
}

void displayArray(int arr[], int n) {
    int i;
    for(i = 0;i < n;i++){
   	 printf("%d\t",arr[i]);
    }
}

void partitionList(NODE *head, int orderedArray[], int orderedNumber, int unOrderedArray[], int unOrderedNumber) {
    int i = 0, j = 0;
    NODE *p = head;

    while(p->next != NULL){
   	 if(p->info < (p->next)->info){
   		 orderedArray[i] = p->info;
   		 orderedArray[i+1] = (p->next)->info;
   		 i+=2;
   	 }else {
   		 unOrderedArray[j] = p->info;
   		 unOrderedArray[j+1] = (p->next)->info;
   	 }
   	 p = (p->next)->next;
    }
    displayArray(orderedArray, orderedNumber);
    //displayArray(unOrderedArray, unOrderedNumber);
}

int main(){
    int n;
    NODE *head = NULL;
    printf("Number of Elements of List : ");
    scanf("%d",&n);
     int rootArray[n];
     head = createList(head, n, rootArray);
     int k = minimumNumberOfDeletions(rootArray, n);
     double ratio_of_Sortdness = k/n;
     int orderedNumber = getNumberofOrderedPairs(rootArray, n);
     int unOrderedNumber = n - orderedNumber;
     int unOrderedArray[unOrderedNumber], orderedArray[orderedNumber];
     printf("%d %d\n",unOrderedNumber, orderedNumber);
     displayArray(orderedArray, orderedNumber);
     displayArray(unOrderedArray, unOrderedNumber);

     partitionList(head, orderedArray, orderedNumber, unOrderedArray, unOrderedNumber);
     printf("%d",k);
}

