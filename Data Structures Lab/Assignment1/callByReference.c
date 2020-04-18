#include <stdio.h>

void swap(int *x, int *y) {
 int temp = *x;
 *x = *y;
 *y = temp;
}

int main() {
 int x=5, y = 4;
 printf("Values before Swap %d %d\n",x,y);
 swap(&x,&y);
 printf("Values after Swap %d %d\n",x,y);
}
