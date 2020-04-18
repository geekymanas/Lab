#include <stdio.h>
int fib(int n) {
 if(n == 1 || n == 0)
 {
  return 1;
 }
 return fib(n-1)+fib(n-2);
}
int main() {
 int n,i;
 scanf("%d",&n);
 printf("0 1 ");
 for(i = 1;i < n;i++){ 
 int result = fib(i);
 printf("%d ",result);
 }
}
