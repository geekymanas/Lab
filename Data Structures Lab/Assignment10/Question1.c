#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct tnode{
  int info;
  struct tnode *rchild, *lchild;
  bool lthread, rthread;
};
typedef struct tnode TNODE;

TNODE *preOrderSucc(TNODE *ptr){
    if(ptr->lthread == true){
        return ptr->rchild;
    }
    ptr = ptr->lchild;
    while(ptr->rthread){
        ptr = ptr->rchild;
    }
    return ptr;
}

TNODE* inOrderSucc(TNODE * root){
    if(root == NULL){
        return NULL;
    }
    
    if(root->rthread == true){
        return root->rchild;
    }
    TNODE *p = root->rchild;
    while(p->lthread == false){
        p = p->lchild;
    }
    return p;
    
}

TNODE* insert(TNODE* root, int key){
    TNODE *ptr = root, *par;;
    while(ptr != NULL){
        if(ptr->info == key){
            printf("Element already present");
            return root;
        }else {
            par = ptr;
            if(key < ptr->info){
                if(ptr->lthread == false){
                    ptr = ptr->lchild;
                }else {
                    break;
                }
            }else {
                if(key > ptr->info){
                    if(ptr->rthread == false){
                        ptr = ptr->rchild;
                    }else {
                        break;
                    }    
                }
            }
        }
    }
    
    TNODE *temp = (TNODE*) malloc(sizeof(TNODE));
    temp->info = key;
    temp->lthread = true;
    temp->rthread = true;
    
    if(par == NULL){
        temp->rchild = NULL;
        temp->lchild = NULL;
        root = temp;
        return root;
    }else {
        if(key < (par->info)){
            temp->lchild = par->lchild;
            temp->rchild = par;
            par->lthread = false;
            par->lchild = temp;
        }else {
            temp->rchild = par->rchild;
            temp->lchild = par;
            par->rchild = temp;
            par->rthread = false;
        }
    }
    return root;
    
}

TNODE *caseA(TNODE *root, TNODE *par, TNODE *ptr){
    if(par == NULL){
        root = NULL;
    }else if(ptr == par->lchild){
        par->lthread = true;
        par->lchild = ptr->lchild;
    }else {
        par->rthread = true;
        par->rchild = ptr->rchild;
    }
    free(ptr);
    return root;

}

TNODE *caseB(TNODE *root, TNODE *par, TNODE *ptr){
    TNODE *child;
    
    if(ptr->lthread == false){
        child = ptr->lchild;
    }else {
        if(ptr->rthread = false){
            child = ptr->rchild;
        }
    }
    
    if(par == NULL){
        root = child;
    }else if(ptr == par->lchild){
        par->lchild = child;
    }else {
        par->rchild = child;
    }
    
    TNODE *s = inOrderSucc(ptr);
    TNODE *p = preOrderSucc(ptr);
    
    if(ptr->lthread == false){
        p->rchild = child;
    }else {
        if(ptr->rthread == false){
            s->lchild = child;
        }
    }
    
    free(ptr);
    return root;
    
}

TNODE *caseC(TNODE *root, TNODE *par, TNODE *ptr){
    TNODE *prsuc = ptr;
    TNODE *suc = ptr->rchild;
    
    while(suc->lchild != NULL){
        prsuc = suc;
        suc = suc->lchild;
    }
    
    ptr->info = suc->info;
    
    if(suc->rthread == true && suc->lthread == true){
        root = caseA(root, prsuc, suc);
    }else {
        root = caseB(root, prsuc, suc);
    }
    return root;
}

TNODE* delete(TNODE *root, int val){
    TNODE *ptr = root, *par = NULL;
    int found = 0;
    while(ptr != NULL){
        if(ptr->info == val){
            found = 1;
            break;
        }else {
            par = ptr;
            if(ptr->info > val){
                if(ptr->lthread == false){
                    ptr = ptr->lchild;
                }else {
                    break;
                }
            }else {
                if(ptr->rthread == false){
                    ptr = ptr->rchild;
                }else {
                    break;
                }
            }
        }
    }
    if(!found){
        printf("The Element Entered is not present in the tree\n");
    }else {
        if(ptr->rthread == true && ptr->lthread == true){
            root = caseA(root, par, ptr);
        }else {
            if(ptr->lthread == true || ptr->rthread == true){
                root = caseB(root, par, ptr);
            }else {
                root = caseC(root, par, ptr);
            }
        }
    }
    return root;
}



void inOrder(TNODE *root){
    if(root == NULL){
        printf("No elements\n");
    }
    TNODE *ptr = root;
    while(ptr->lthread == false){
        ptr = ptr->lchild;
    }
    
    while(ptr != NULL){
        printf("%d ", ptr->info);
        ptr = inOrderSucc(ptr);
    }
    printf("\n");
}

int main(){
    int n, val;
    TNODE *root = NULL;
    while(1){
        printf("1.Insert\n2.Delete\n3.Display Inorder\n");
        scanf("%d",&n);
        switch(n){
            case 1:
                scanf("%d",&val);
                root = insert(root, val);
                break;
            case 2:
                scanf("%d",&val);
                root = delete(root, val);
                break;
            case 3:
                inOrder(root);
                break;
        }
    }
       
}

