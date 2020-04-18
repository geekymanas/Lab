#include <stdio.h>

int  binarySearch(int a[], int start, int end, int num) {
 int mid = end-start/2 ;
 if(end>=1) {
  if(a[mid] == num) {
   return mid;
  }
  if(a[mid]>num) {
   return binarySearch(a, 0,mid-1,num);
  }
  if(a[mid] < num) {
   return binarySearch(a, mid+1, end, num);
  }
  return -1;
 }
}
int main()
{
 printf("Enter The Size of Array..");
 int n,i,num;
 scanf("%d",&n);
 int a[n];
 printf("Enter The Number to be Searched For..");
 scanf("%d",&num);
 for(i = 0;i < n;i++)
 {
  scanf("%d",&a[i]);
 }
 int result =  binarySearch(a, 0, n, num);
 (result == -1)?printf("The Number is not present"):printf("The Number is Present at %d",result);
}
