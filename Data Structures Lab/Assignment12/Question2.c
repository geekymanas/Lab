
void printArray(int arr[]){
    int i = 0;
    for(i = 0;i < 5;i++) {
   	 printf("%d ",arr[i]);
    }
    printf("\n");
}

int main() {
    int i, j, n;
    scanf("%d",&n);
    int arr[n];
    for(i = 0;i < n;i++){
   	 scanf("%d",&arr[i]);
    }
    for(i = 0;i < n-1;i++){
   	 for(j = 0;j < n;j++){
   		 if(arr[j] < arr[i]) {
   			 if(j != i) {
   				 int temp  = arr[i];
   				 arr[i] = arr[j];
   				 arr[j] = temp;
   			 }
   		 }

   	 }
    }
   printArray(arr);
}
