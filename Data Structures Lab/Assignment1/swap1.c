#include <stdio.h>
int main() {
 int x, y;
 scanf("%d%d",&x,&y);
 x+=y;
 y=x-y;
 x=x-y;
 printf("%d\t%d",x,y);
}
