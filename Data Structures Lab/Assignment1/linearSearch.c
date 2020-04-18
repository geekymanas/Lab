#include <stdio.h>
int linearSearch(int ar[], int num, int p, int n) {
 if(ar[p] == num) {
    return p;
 }
 p++;
 if(p+1 == n)
 {
  return -1;
 }
 return linearSearch(ar,num,p,n);
}
int main() {
 int n, num, i;
 printf("Enter The size of array..");
 scanf("%d",&n);
 int ar[n];
 printf("Enter The Number to be Searched for");
 scanf("%d",&num);
 for(i = 0;i < n;i++) {
  scanf("%d",&ar[i]);
 }
 int result = linearSearch(ar,num,0,n);
 if(result == -1) {
  printf("The given number is not present in the array");
 }else {
  printf("The given number is at %d ",result);
 }
}

