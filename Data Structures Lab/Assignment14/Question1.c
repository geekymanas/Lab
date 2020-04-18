#include <stdio.h>
#include <stdlib.h>
int origin, dest;
struct node {
    struct node *point;
    int info;
    struct node *next;
}*start = NULL;
typedef struct node NODE;
void createGraph(){
    int n, max_edges, info, i;
    NODE *temp, *ptr;
    printf("Enter number of vertices\n");
    scanf("%d",&n);
    max_edges = n*(n-1);
    for(i = 0;i < n;i++){
   	 printf("Enter vertices info\n");
   	 scanf("%d",&info);
   	 temp = (NODE*) malloc(sizeof(NODE));
   	 temp->info = info;
   	 temp->point = NULL;
   	 temp->next = NULL;
   	 if(start == NULL){
   		 start = temp;
   	 }else {
   		 ptr = start;
   		 while(ptr->next != NULL){
   			 ptr = ptr->next;
   		 }
   		 ptr->next = temp;
   	 }
    }
}

NODE *findNode(int u){
    NODE *ptr = start;
    while(ptr->info != u || ptr != NULL){
   	 ptr = ptr->next;
    }
    if(ptr->info == u){
   	 return ptr;
    }else {
   	 return NULL;
    }
}

void insertEdge() {
    NODE  *ptr, *locu, *locv;
    locu = findNode(origin);
    locv = findNode(dest);
    if(locu == NULL || locv == NULL){
   	 printf("Enter proper vertices\n");
   	 return;
    }
    ptr = locu;
    NODE *temp = (NODE*) malloc(sizeof(NODE));
    temp->point = locv;
    temp->next = NULL;
    if(locu->point == NULL){
   	 locu->point = temp;
    }
    while(ptr->next != NULL){
   	 ptr = ptr->next;
    }
    ptr->next = temp;
}

void insertNode(int info){
    NODE *temp, *ptr;
    temp = (NODE*) malloc(sizeof(NODE));
    temp->point = NULL;
    temp->next = NULL;
    ptr = start;
    while(ptr->next != NULL){
   	 ptr = ptr->next;
    }
    ptr->next = temp;
}

void deleteNode(int info){
    NODE *locu = findNode(info), *locv;
    NODE *ptr, *temp, *q, *pointer;
    if(locu == NULL){
   	 return;
    }
    ptr = start;
    while(ptr != NULL){
   	 q = ptr->point;
   	 while(q != NULL){
   		 pointer = q;
   		 if(q->point == locu){
   			 if(q == ptr->point){
   				 temp = q;
   				 ptr->point = q->next;
   				 free(temp);
   			 }else {
   				 temp = q;
   				 pointer->next = q->next;
   				 free(temp);
   			 }

   		 }
   	 }
    }
    ptr = start;
    while(ptr->next != locu){
   	 ptr = ptr->next;
    }
    temp = ptr->next;
    ptr->next = temp->next;
    free(temp);

}

void deleteEdge(){
    NODE *locu = findNode(origin);
    NODE *locv = findNode(dest);
    NODE *temp, *ptr;
    if(locu->point == locv){
   	 temp = locu->point;
   	 locu->point = temp->next;
   	 free(temp);
   	 return;
    }
    ptr = locu->point;
    while(ptr->next->point != locv){
   	 ptr = ptr->next;
    }
    temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
}

int main(){
    int choice, info;
    createGraph();
    while(1){
        	printf("1.Insert Edge\n2.Delete Edge\n3.Insert node\n4.Delete node\n5.Exit\n");
        	scanf("%d",&choice);
        	switch(choice){
        	case 1:
            	printf("Enter edge origin and destination\n");
            	scanf("%d%d",&origin,&dest);
            	insertEdge();
            	break;
        	case 2:
            	printf("Enter origin and destination of edge to be deleted\n");
            	scanf("%d%d",&origin,&dest);
            	deleteEdge();
            	break;
        	case 3:
       		 printf("Enter vertex info\n");
       		 scanf("%d",&info);
            	insertNode(info);
            	break;
        	case 4:
       		 printf("Enter vertex info\n");
       		 scanf("%d",&info);
            	deleteNode(info);
            	break;
        	case 5:
                	return 1;
        	default:
            	printf("Enter valid option\n");
        	}
	}
}

