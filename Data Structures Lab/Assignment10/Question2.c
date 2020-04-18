#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
 struct node *right,*left,*prev;
 char data;
}*cur,*par,*root=NULL;

void inorder(struct node *root)
{
 if(root!=NULL)
 {
  inorder(root->left);
  printf("%c ",root->data);
  inorder(root->right);
 }
}

void preorder(struct node *root)
{
 if(root!=NULL)
 {
  printf("%c ",root->data);
  preorder(root->left);
  preorder(root->right);
 }
}

void postorder(struct node *root)
{
 if(root!=NULL)
 {
  postorder(root->left);
  postorder(root->right);
  printf("%c ",root->data);
 }
}
void main()
{
  char a[100];
  int len,i;
  struct node *new_node;

  printf("Enter Postfix Expression\n");
  gets(a);
  len = strlen(a);
  for(i=len-1 ; i>=0 ; i--)
  {
   new_node=(struct node *)malloc(sizeof(struct node));
   new_node->data=a[i];
   new_node->left=new_node->right=new_node->prev=NULL;
   if(root==NULL)
   {
 	root=new_node;
 	cur=par=root;
   }
   else
   {
	if(a[i]=='+' ||a[i]=='-' ||a[i]=='*'||a[i]=='/')
	{
 	if(par->right==NULL)
 	{
  	cur=new_node;
  	par->right=cur;
  	cur->prev=par;
  	par=cur;
 	}
 	else if(par->left==NULL)
 	{
  	cur=new_node;
  	par->left=cur;
  	cur->prev=par;
  	par=cur;
 	}
	else
	{
 	while(par->left!=NULL)
 	{
  	par=par->prev;
 	}
 	cur=new_node;
 	par->left=cur;
 	cur->prev=par;
 	par=cur;
	}
   }
   else
   {
	if(par->right==NULL)
	{
 	cur=new_node;
 	par->right=cur;
 	cur->prev=par;
	}
	else if(par->left==NULL)
	{
 	cur=new_node;
 	par->left=cur;
 	cur->prev=par;
	}
	else
	{
 	while(par->left!=NULL)
 	{
  	par=par->prev;
 	}
 	cur=new_node;
 	par->left=cur;
 	cur->prev=par;
	}
   }
  }
 }
 printf("Select Option\n1.PreOrder\n2.postorder\n3.Inorder\n");
 int n;
 scanf("%d",&n);
 if(n == 1){
	 printf("\n\nPreorder Traversal: \n");
	 preorder(root);
}else {
    if(n == 2){
   	 printf("\n\nPostorder Traversal: \n");
   	  postorder(root);   	 
    }
    else{
		 printf("\nInorder Traversal: \n");
		 inorder(root);
    }
 }
}

