#include <stdio.h>

int n, m, x, y, size;

int getSparseData(int sparse_matrix[n][m]) {
   int i, j, size = 0;
   for(i = 0;i < n;i++) {
  	 for(j = 0;j < m;j++) {
  		 scanf("%d",&sparse_matrix[i][j]);
  		 if(sparse_matrix[i][j] != 0 ) {
  			 size++;
  		 }
  	 }
   }
   return size;
}

void makeTripletMatrix(int sparse_matrix[n][m], int tripletMatrix[3][size]) {
    int i, j, k = 1;
    tripletMatrix[0][0] = 1;
    tripletMatrix[0][1] = 2;
    tripletMatrix[0][2] = 3;
    for(i = 0;i < n;i++) {
   	 for(j = 0;j < m;j++) {
   		 if(sparse_matrix[i][j]  != 0) {
   			 tripletMatrix[0][k] = i;
   			 tripletMatrix[1][k] = j;
   			 tripletMatrix[2][k] = sparse_matrix[i][j];
   			 k++;
   		 }
   	 }
    }
}

void printTripletMatrix(int tripletMatrix[3][size]) {
    int i, j;
    for(i = 0;i < size;i++) {
   	 for(j = 0;j < 3;j++) {
   		 printf("%d\t",tripletMatrix[j][i]);
   	 }
   	 printf("\n");
    }
}

int main() {
    printf("Enter The Row and Column Dimension\n");
    scanf("%d%d",&n,&m);
    int sparse_matrix[n][m];
    size = getSparseData(sparse_matrix);
    int tripletMatrix[3][size];

    makeTripletMatrix(sparse_matrix, tripletMatrix);
    printTripletMatrix(tripletMatrix);
}

