#include <stdio.h>

void printArray(int arr[], int n){
    int i = 0;
    for(i = 0;i < n;i++) {
   	 printf("%d ",arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int l, int m, int r){
    int i, j, k = 1;
    int n1 = m-l+1, n2 = r-m;
    int l1[n1], l2[n2];
    for(i = 0;i < n1;i++){
   	 l1[i] = arr[l+i];
    }
    for(j = 0;j < n2;j++){
   	 l2[j] = arr[m+j+1];
    }
    i = 0;
    j = 0;
    while(i < n1 && j < n2) {
   	 if(l1[i] <= l2[j]){
   		 arr[k] = l1[i];
   		 k++;
   		 i++;    
   	 }else {
   		 arr[k] = l2[j];
   		 k++;
   		 j++;
   	 }
    }

    while(i < n1){
   	 arr[k] = l1[i];
   	 k++;
   	 i++;
    }
    while(j < n2){
   	 arr[k] = l2[j];
   	 k++;
   	 j++;
    }
}

void mergeSort(int arr[], int l, int r){
    int m = (l+r)/2;
    if(l < r){
   	 mergeSort(arr, l, m);
   	 mergeSort(arr, m+1, r);
   	 merge(arr, l, m, r);
    }
}


int main() {
    int i, j, n;
    scanf("%d",&n);
    int arr[n];
    for(i = 0;i < n;i++){
   	 scanf("%d",&arr[i]);
    }
    mergeSort(arr, 0, n-1);
    printArray(arr, n);
}

