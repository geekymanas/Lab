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

struct mlnode {
    int info, row, col;
    struct mlnode  *nextRow, *nextCol;
};
typedef struct mlnode MLNODE;

MLNODE* above(MLNODE *head, int row, int col) {
    MLNODE *p = head->nextRow, *q;
    while(p->col != col) {
   	 p = p->nextCol;
    }
    do{
   	 q = p;
   	 p = p->nextRow;
    }while(p->row < r && p->col == -1);
    return q;
}

MLNODE* left(MLNODE* head, int row, int col) {
    MLNODE *p = head->nextRow, *q;
    while(p->row != r) {
   	 p = p->nextRow;
    }
    do{
   	 q = p;
   	 p = p->nextCol;
    }while(p->col < col && p->col != --1);
    return q;
}

MLNODE* insert(MLNODE *head, int row, int col, int info) {
    MLNODE *above, *left;
    MLNODE *p = (MLNODE*) malloc(sizeof(MLNODE));
    above = above(head, row, col);
    left = left(head, row, col);
    p->info = val;
    p->nextRow = above->nextRow;
    above->nextRow = p;
    p->nextCol = left->nextCol;
    left->nextCol = p;
    return head;
}

void delete(MLNODE* head, int row, int col) {
    MLNODE *above *left, *p;
    above = above(head, row, col);
    left = left(head, row, col);
    above->nextRow = (above->nextRow)->nextRow;
    above->nextCol = (above->nextCol)->nextCol;
    left->nextCol = (left->nextCol)->nextCol;
    left->nextRow = (left->nextRow)->nextRow;
    p = a->nextRow;
    free(p);
}

void display(MLNODE *head) {
    MLNODE *p = head, *q = head;
    while(p->nextRow != head)  {
   	 p = p->nextRow;
   	 while(q->nextCol != p) {
   		 printf("%d", p->info);
   	 }
    }
    printf("%d\n",p->info);
}

MLNODE* deleteRow(MLNODE *head, int r) {
    MLNODE *p = head->nextRow, *z;
    while(p->row != row) {
   	 z = p;
   	 p = p->nextRow;
    }
    p = p->nextCol;
    while(p->col != -1) {
   	 q = p->nextCol;
   	 delete(head, p->row, p->col);
   	 p = q;
    }
    p = p->nextRow;
    while(p->row != -1) {
   	 p->row  = (p->row) -1;
    }
    z->nextRow = q->nextRow;
    free(q);
}

int main() {
    int i, j, del;
    MLNODE* head = (MLNODE*) malloc(sizeof(MLNODE));
    head->row = -1;
    head->col = -1;
    head->nextRow = NULL;
    head->nextCol = NULL;
    int i, j;
    printf("Enter The Row and Column Dimension\n");
    scanf("%d%d",&n,&m);
    int sparse_matrix[n][m];
    size = getSparseData(sparse_matrix);
    int a = 0, b = -1;
    NODE* p = head;
    for(i = 0;i < n;i++) {
   	 MLNODE *q = (MLNODE*) malloc(sizeof(MLNODE));
   	 q->row = b;
   	 q->col = a;
   	 b++;
   	 q->nextRow = NULL;
   	 q->nextCol = NULL;
   	 p->nextRow = q;
   	 p = q;
    }
    a = -1;
    b = 0;
    p = head;
    for(i = 0;i < m;i++) {
   	 MLNODE *q = (MLNODE*) malloc(sizeof(MLNODE));
   	 q->row = a;
   	 q->col = b;
   	 b++;
   	 q->nextRow = NULL;
   	 q->nextCol = NULL;
   	 p->nextCol = q;
   	 p = q;
    }
    for(i = 0;i < n;i++) {
   	 for(j = 0;j < m;j++) {
   		 head  = insert(head, i, j, sparse_matrix[i][j]);
   	 }
    }
    printf("Enter The Row That You want to to delete\n");
    scanf("%d",&del);
    head = deleteRow(MLNODE *head, int del);
}

