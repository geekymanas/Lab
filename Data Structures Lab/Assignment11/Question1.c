#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *left,*right;
};
typedef struct node NODE;
NODE* insert(NODE *root,int x);
NODE* delete(NODE *root,int x);
void preorder(NODE *root);
void inorder(NODE *root);
void postorder(NODE *root);
NODE* rotateright(NODE *root);
NODE* rotateleft(NODE *root);
int BF(NODE *root);
NODE* LL(NODE *root);
NODE* LR(NODE *root);
NODE* RR(NODE *root);
NODE* RL(NODE *root);
void main()
{
	NODE *root=NULL;
	int choice,x,i;
	printf("\n1.Insert Node\n2.Delete Node\n3.Display Data\n4.Exit");
	while(1)
	{
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter data to be inserted:");
					scanf("%d",&x);
					root=insert(root,x);
					break;
			case 2:printf("Enter element to be deleted:");
					scanf("%d",&x);
					root=delete(root,x);
					break;
			case 3: printf("Pre-order repersantation\n");
					preorder(root);
					printf("In-order repersantation\n");
					inorder(root);
					printf("Post-order repersantation");
					postorder(root);
					break;
			case 4:exit(1);
			default:printf("INVALID CHOICE");
		}
	}
}

NODE* insert(NODE *root,int x)
{
	if(root==NULL)
	{
		root=(NODE*)malloc(sizeof(NODE));
		root->info=x;
		root->left=NULL;
		root->right=NULL;
	}
	else if(x>root->info)
	    {
			root->right=insert(root->right,x);
			if(BF(root)==-2)
				if(x>root->right->info)
					root=RR(root);
				else
					root=RL(root);
		}
		else
			if(x<root->info)
			{
				root->left=insert(root->left,x);
				if(BF(root)==2)
					if(x<root->left->info)
						root=LL(root);
					else
						root=LR(root);
			}
			return root;
}
NODE* delete(NODE *root,int x)
{
	NODE *p;
	if(root==NULL)
		return NULL;
	else if(x>root->info)
	    {
			root->right=delete(root->right,x);
			if(BF(root)==2)
				if(BF(root->left)>=0) 
					root=LL(root);
				else
					root=LR(root);
		}
		else if(x<root->info)
		{
			root->left=delete(root->left,x);
			if(BF(root)==-2)
				if(BF(root->right)<=0)
					root=RR(root);
				else 
					root=RL(root);
		}
		else//x is found
		{
			if(root->right!=NULL)
			{
				p=root->right;
				while(p->left!=NULL)
					p=p->left;
				root->info=p->info;
				root->right=delete(root->right,p->info);
				if(BF(root->left)>=0)
					root=LL(root);
				else
					root=LR(root);
			}
			else
				return root->left;
		}
		return root;
}
int height(NODE *root)
{
	int leftheight,rightheight;
	if(root==NULL)
		return 0;
	else{
			leftheight=height(root->left);
			rightheight=height(root->right);
			if(leftheight>rightheight)
				return (1+leftheight);
			else return (1+rightheight);
	}
}
int BF(NODE *root)
{
	int lh=height(root->left);
	int rh=height(root->right);
	return (lh-rh);
}
NODE* rotateleft(NODE *root)
{
		NODE *p;
		p=root->right;
		root->right=p->left;
		p->left=root;
		return p;
}
NODE* rotateright(NODE *root)
{
	NODE *p;
	p=root->left;
	root->left=p->right;
	p->right=root;
	return p;
}
NODE* LL(NODE *root)
{
	root=rotateright(root); 
	return root;
}
NODE* RR(NODE *root)
{
	root=rotateleft(root);
	return root;
}
NODE* LR(NODE *root)
{
	root->left=rotateleft(root->left);
	root=rotateright(root);
	return root;
}
NODE* RL(NODE *root)
{
	root->right=rotateright(root->right);
	root=rotateleft(root);
	return root;
}
	void preorder(NODE *T)
{
    if(T!=NULL)
    {
        printf("%d(Bf=%d)",T->info,BF(T));
        preorder(T->left);
        preorder(T->right);
    }
}	
	
	void inorder(NODE *T)
{
    if(T!=NULL)
    {
		 preorder(T->left);
        printf("%d(Bf=%d)",T->info,BF(T));
        preorder(T->right);
    }
}
	void postorder(NODE *T)
{
    if(T!=NULL)
    {
		 preorder(T->left);
        preorder(T->right);
		    printf("%d(Bf=%d)",T->info,BF(T));
    }
}

