#include <stdio.h>

void swap(int x, int y) {
 int temp = x;
 x = y;
 y = temp;
} 

int main() {
 int x = 5, y = 4;
 printf("Value Before Swapping %d %d\n",x,y);
 swap(x, y);
 printf("Value After Swapping %d %d\n",x,y);
 return 0;
}
