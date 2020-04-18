#include <stdio.h>
#include <stdlib.h>
#define COUNT 10

struct listnode {
  char info;
  struct listnode *next;
};

typedef struct listnode lnode;

struct treenode {
  char info;
  struct treenode *left;
  struct treenode *right;
};

typedef struct treenode tnode;

lnode* new_lnode(char info) {
	lnode* p = (lnode*) malloc(sizeof(lnode));
	p->next = NULL;
	p->info = info;
	return p;
}

tnode* new_tnode(char info) {
	tnode* p = (tnode*) malloc(sizeof(tnode));
	p->left = NULL;
	p->right = NULL;
	p->info = info;
	return p;
}

lnode* insertToList(lnode* head, char info) {
	lnode *p = head;
	lnode *q = (lnode*) malloc(sizeof(lnode));
	q->next = NULL;
	q->info = info;
	if(p == NULL) {
  	return q;
	}
	while(p->next != NULL){
  	p = p->next;
	}
	p->next = q;
	return head;
}

tnode* constructPre(lnode *inptr, lnode *preptr, int num) {
	tnode *temp;
	lnode *q;
	int i, j;
	if(num == 0) {
  	return 0;
	}
	temp = (tnode*) malloc(sizeof(tnode));
	temp->info = preptr->info;
	temp->left = NULL;
	temp->right = NULL;
	if(num == 1) {
  	return temp;
	}
	q = inptr;
	for(i = 0;q->info != preptr->info;i++) {
  	q = q->next;
	}
	temp->left = constructPre(inptr, preptr->next, i);
	for(j = 1;j <= i+1;j++) {
  	preptr = preptr->next;
	}
	temp->right = constructPre(q->next, preptr, num-i-1);
	return temp;

}

tnode* constructPost(lnode* inptr, lnode* postptr, int num) {
  tnode *temp;
  lnode *q, *ptr;
  int i, j;
  if(num == 0) {
	return NULL;
  }
  ptr = postptr;
  while(ptr->next != NULL) {
	ptr = ptr->next;
  }
  temp = (tnode*) malloc(sizeof(tnode));
  temp->info = ptr->info;
  temp->left = NULL;
  temp->right = NULL;
  if(num == 1) {
	return temp;
  }
  q = inptr;
  for(i = 1;q->info != ptr->info;i++) {
	q = q->next;
  }
  temp->left = constructPost(inptr, postptr, i);
  for(j = 0;j <= i;j++) {
	postptr = postptr->next;
  }
  temp->right = constructPost(q->next, postptr, num-i-1);
  return temp;
}

void print2DUtil(tnode *root, int space)
{  
	if (root == NULL)
    	return;
	space += COUNT;
	print2DUtil(root->right, space);
 
	printf("\n");
	for (int i = COUNT; i < space; i++)
    	printf(" ");
	printf("%c\n", root->info);
 
	print2DUtil(root->left, space);
}

int main() {
  char c = ' ';
  int num = 0, n;
  lnode* inptr = NULL;
  lnode* preptr = NULL;
  lnode* postptr = NULL;
 
  printf("1.Using Preorder\n2.Using Postorder\n");
  scanf("%d",&n);
  if(n == 1) {
  printf("Enter The preOrder traversal\n");
  while((c = getchar()) != '\n' && c != EOF) {
  	num++;
  	preptr = insertToList(preptr, c);
  }
 }else {
  printf("Enter The postOrder traversal\n");
  while((c = getchar()) != '\n' && c != EOF) {
  	num++;
  	postptr = insertToList(postptr, c);
  }
 }
  printf("Enter The inOrder traversal\n");
  while((c = getchar()) != '\n' && c != EOF) {
  	inptr = insertToList(inptr, c);
  }
 
  if(n == 1){
   tnode* tree = constructPre(inptr, preptr, num);
 	print2DUtil(tree, 0);

  }else {
   tnode* tree = constructPost(inptr, postptr, num);    
	print2DUtil(tree, 0);
  }

}

