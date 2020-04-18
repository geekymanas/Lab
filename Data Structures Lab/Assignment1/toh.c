#include <stdio.h>
void toh(int n, char source,char temp,char dest) {
 if(n==1) {
  printf("Move Disk %d from %c->%c\n,",n,source,dest);
  return;
 }
 toh(n-1,source,dest,temp);
 printf("Move Disk %d from %c-->%c\n",n,source,dest);
 toh(n-1,source,temp,dest);
}
int main() {
 char source ='A', temp='B',dest='C';
 int n;
 printf("Enter the number of disks : ");
 scanf("%d",&n);
 printf("The Sequence is ");
 toh(n,source,temp,dest);
 return 0;
}
