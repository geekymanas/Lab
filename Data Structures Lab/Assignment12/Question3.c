#include <stdio.h>

int main() {
    int i, j, n;
    scanf("%d",&n);
    int arr[n];
    for(i = 0;i < n;i++){
   	 scanf("%d",&arr[i]);
    }
    for(i = 1;i < n;i++){
   	 int temp = arr[i];
   	 for(j = i-1;j >= 0 && (temp < arr[j]);j--){
   			 arr[j+1] = arr[j];   		 
   	 }
   	 arr[j+1] = temp;
    }
    for(i = 0;i < n;i++){
   	 printf("%d\t",arr[i]);
    }
}

