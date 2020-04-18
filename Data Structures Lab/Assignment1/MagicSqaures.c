#include <stdio.h>

int main() {
    int n;
    printf("Enter size of magic square: ");
    scanf("%d", &n);
    int magic[99][99];
    int start = (n / 2); 
    int max = n * n; 
    magic[0][start] = 1; 
    int row;
    int col;
    int next_row;
    int next_col;
    int i;
    for (i = 2, row = 0, col = start; i < max + 1; i++) {
        if ((row - 1) < 0) { 
            next_row = n - 1; 
        }
        else { next_row = row - 1; } 
        if ((col + 1) > (n - 1)) { 
            next_col = 0; 
        }                                                                         
        else { next_col = col + 1; }                     

        if (magic[next_row][next_col] > 0) {         
            if (row > (n - 1)) {            
                next_row = 0;                                
            }                                                                     
            else {                                                                
                next_row = row + 1;                        
                next_col = col;                         
            }                                                                     
        }                                                                         
        row = next_row;                                                           
        col = next_col;                                                           
        magic[row][col] = i; //             
    }                                                                             
    int j;                                                                        
    for (i = 0; i < n; i++) {                                                     
        for (j = 0; j < n; j++) {                                                 
            printf("%4d", magic[i][j]);                                           
        }                                                                         
        printf("\n");                                                             
    }                                                                             
    return 0;                                                                     
}
