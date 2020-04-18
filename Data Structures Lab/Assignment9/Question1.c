#include <stdio.h>
#include <stdlib.h>

struct btnode {
    int info, count;
    struct btnode *lchild, *rchild;
};

typedef struct btnode BTNODE;

BTNODE* createNode(int info) {
    BTNODE *p = (BTNODE*) malloc(sizeof(BTNODE));
    p->lchild = NULL;
    p->rchild = NULL;
    p->info = info;
    return p;
}

BTNODE* delete(BTNODE* root, int data)
{    if(root == NULL) {
   	 return NULL;
    }
    BTNODE *ptr = root, *prev = NULL, *cur;
    while(ptr->info != data && ptr != NULL) {
   	 prev = ptr;
   	 printf("%d\n",ptr->info);
   	 if(ptr->info > data) {
   		 ptr = ptr->lchild;
   	 }else{
   		 if(ptr->info < data) {
   			 ptr = ptr->lchild;
   		 }else {
   			 break;
   		 }
   	 }
    }
    printf("Here\n");
    cur = ptr;
    if(ptr->lchild == NULL && ptr->rchild == NULL) {
   	 if(prev->lchild == ptr) {
   		 prev->lchild = NULL;
   	 }else {
   		 prev->rchild = NULL;
   	 }
   	 free(ptr);
    }else {
   	 if(ptr->rchild != NULL) {
   		 ptr = ptr->rchild;
   		 if(ptr->lchild != NULL) {
   			 ptr = ptr->lchild;
   			 while(ptr->lchild != NULL) {
   				 ptr = ptr->lchild;
   			 }
   			 prev->info = ptr->info;
   	     	 free(ptr);
   		 }else{
   			 cur->info = ptr->info;
   			 free(ptr);
   		 }    
   	 
   	 }else {
   		 if(ptr->lchild != NULL) {
   			 if(prev->lchild = ptr){
   				 prev->lchild = ptr->lchild;   				 
   			 }else {
   				 prev->rchild = ptr->lchild;
   			 }
   		 }
   	 }
    }
    return root;
}

BTNODE* insert(BTNODE *root, int info) {
    BTNODE *p = createNode(info);
    if(root == NULL) {
   	 return createNode(info);
    }else if(info < root->info) {
   	 root->lchild = insert(root->lchild, info);
    }else if(info > root->info) {
   	 root->rchild = insert(root->rchild, info);
    }else if(info == root->info) {
   	 root->count++;
    }else {
   	 return root;
    }
}

void printInorder(BTNODE *root) {
    if(root != NULL) {
   	 printInorder(root->lchild);
   	 printf("%d ",root->info);
   	 printInorder(root->rchild);
    }
}

void printPostOrder(BTNODE *root) {
    if(root != NULL) {
   	 printInorder(root->lchild);
   	 printInorder(root->rchild);
   	 printf("%d ",root->info);
    }
}

void printPreOrder(BTNODE *root) {
    if(root != NULL) {
   	 printf("%d ",root->info);
   	 printInorder(root->lchild);
   	 printInorder(root->rchild);
    }    
}

int main() {
    BTNODE *root;
    int n, info,i;
    for(i = 0;i < 7;i++) {
   	 root = insert(root,i);
    }
    while(1){
   	 printf("Welcome to Binart Search  Tree\n");
   	 printf("1.Insert element\n2.Delete element\n3.Print Inorder\n4.Print postorder\n5.Print preorder\n");
   	 scanf("%d",&n);
   	 switch(n) {
   		 case 1:
   			 printf("Enter The element\n");
   			 scanf("%d",&info);
   			 root = insert(root, info);
   			 break;
   		 case 2:
   			 printf("enter the element to be deleted\n");
   			 scanf("%d",&info);
   			 root = delete(root, info);
   			 break;
   		 case 3:
   			 printInorder(root);
   			 break;
   		 case 4:
   			 printPostOrder(root);
   			 break;
   		 case 5:
   			 printPreOrder(root);
   			 break;
   		 default:
   			 printf("Enter Valid Option\n");
   			 break;   		 
   	 }
    }    
}

