#include <stdio.h>

int main(){
    int n, increment, k, j;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    int arr[n];
    for(i = 0;i < n;i++){
   	 scanf("%d",&arr[i]);
    }
    printf("Enter the increment\n");
    scanf("%d",&increment);
    while(increment >= 1){
   	 for(i = increment;i < n;i++){
   		 k = arr[i];
   		 for(j = i-increment;j>= 0 && k < arr[j];j = j-increment){
   			 arr[j+increment] = arr[j];
   		 }
   		 arr[j+increment] = k;
   	 }
   	 increment = increment-2;
    }
    pritf("The Sorted array is \n");
    for(i = 0;i < n;i++){
   	 printf("%d",arr[i]);
    }
}

