#include <stdio.h>

void printArray(int arr[], int n){
    int i = 0;
    for(i = 0;i < n;i++) {
   	 printf("%d ",arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high){
    int pivot = arr[high-1], i = low - 1, j;
    for(j = low;j < high-1;j++){
   	 if(arr[j] <= pivot){
   		 i++;
   		 int temp = arr[i];
   		 arr[i] = arr[j];
   		 arr[j] = temp;
   	 }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high-1];
    arr[high-1] = temp;
    return i+1;
}

void quickSort(int arr[], int low, int high){
    if(low < high) {
   	 int pi = partition(arr, low, high);
   	 quickSort(arr,low, pi-1);
   	 quickSort(arr,pi+1, high);
    }
}

int main() {
    int i, j, n;
    scanf("%d",&n);
    int arr[n];
    for(i = 0;i < n;i++){
   	 scanf("%d",&arr[i]);
    }
    quickSort(arr, 0, n-1);
    printArray(arr, n);
}

