#include <stdio.h>
#include <stdlib.h>
struct edge;
struct vertex {
    int info;
    struct vertex *nextVertex;
    struct edge *firstEdge;
}*start = NULL;
typedef struct vertex VERTEX;
struct edge
{
    struct vertex *destVertex;
    struct edge *nextEdge;    
};
typedef struct edge EDGE;
void insertVertex(int u);
void insertEdge(int u, int v);
void deleteVertex(int u);
void deleteEdge(int u, int v);
int degreeNode(int u);
void display();
VERTEX* findVertex(int u);
int main() {
    int choice, origin, u, dest;
    while(1){
   	 printf("1.Insert Node\n2.Insert Edge\n3.Delete Node\n4.Delete edge\n5.Degree of Node\n6.Display\n7.Exit\n");
   	 scanf("%d",&choice);
   	 switch(choice){
   		 case 1:
   			 printf("Enter a vertex to be inserted\n");
   			 scanf("%d",&u);
   			 insertVertex(u);
   			 break;
   		 case 2:
   			 printf("Enter origin and destination\n");
   			 scanf("%d%d", &origin, &dest);
   			 insertEdge(origin, dest);
   			 break;
   		 case 3:
   			 printf("Enter node to be deleted\n");
   			 scanf("%d",&u);
   			 deleteVertex(u);
   			 break;
   		 case 4:
   			 printf("Enter origin and destination\n");
   			 scanf("%d%d",&origin,&dest);
   			 deleteEdge(origin, dest);
   			 break;
   		 case 5:
   			 printf("Enter the node\n");
   			 scanf("%d",&u);
   			 printf("The Degree of node is %d",degreeNode(u));
   			 break;
   		 case 6:
   			 display();
   			 break;
   		 case 7:
   			 exit(1);   					 
   	 }
    }
}

void insertVertex(int u){
    VERTEX *temp, *ptr;
    temp = (VERTEX*) malloc(sizeof(VERTEX));
    temp->info = u;
    temp->nextVertex = NULL;
    temp->firstEdge = NULL;
    if(start == NULL){
   	 start = temp;
   	 return;
    }
    ptr = start;
    while(ptr->nextVertex != NULL){
   	 ptr = ptr->nextVertex;
    }
    ptr->nextVertex = temp;
}

void deleteVertex(int u){
    VERTEX *temp, *q;
    EDGE *p, *temporary;
    if(start == NULL){
   	 printf("NO nodes in list\n");
   	 return;
    }
    if(start->info == u){
   	 temp = start;
   	 start = start->nextVertex;
    }else {
   	 q = start;
   	 while(q->nextVertex != NULL){
   		 if(q->nextVertex->info == u){
   			 break;
   		 q = q->nextVertex;    
   		 }
   	 }
   	 if(q->nextVertex == NULL){
   		 printf("No node found\n");
   	 }else {
   		 temp = q->nextVertex;
   		 q->nextVertex = temp->nextVertex;
   	 }
    }
    p = temp->firstEdge;
    while(p != NULL){
   	 temporary = p;
   	 p = p->nextEdge;
   	 free(temporary);
    }
    free(temp);
}

VERTEX* findVertex(int u){
    VERTEX *ptr;
    ptr = start;
    while(ptr != NULL){
   	 if(ptr->info == u){
   		 return ptr;
   	 }
   	 ptr = ptr->nextVertex;
    }
    return NULL;
}

void insertEdge(int u, int v){
    VERTEX *locu, *locv;
    EDGE *ptr, *temp;
    locu = findVertex(u);
    locv = findVertex(v);
    if(locu == NULL || locv == NULL){
   	 printf("Not valid vertcies\n");
   	 return;
    }
    temp = (EDGE*) malloc(sizeof(EDGE));
    temp->destVertex = locv;
    temp->nextEdge = NULL;
    if(locu->firstEdge == NULL){
   	 locu->firstEdge = temp;
   	 return;
    }
    ptr = locu->firstEdge;
    while(ptr->nextEdge != NULL){
   	 ptr = ptr->nextEdge;
    }
    ptr->nextEdge = temp;
}

void deleteEdge(int u, int v){
    VERTEX *locu;
    EDGE *ptr, *temp;
    locu = findVertex(u);
    if(locu == NULL){
   	 printf("First insert origin\n");
   	 return;
    }
    if(locu->firstEdge->destVertex->info == v){
   	 temp = locu->firstEdge;
   	 locu->firstEdge = NULL;
   	 free(temp);
   	 return;
    }
    ptr = locu->firstEdge;
    while(ptr->nextEdge != NULL){
   	 if(ptr->nextEdge->destVertex->info == v){
   		 temp = ptr;
   		 temp->nextEdge = ptr->nextEdge;
   		 free(temp);
   		 return;
   	 }
   	 ptr = ptr->nextEdge;
    }
    printf("Edge is not present\n");
}

void display(){
    VERTEX *ptr;
    EDGE *q;
    ptr = start;
    while(ptr != NULL){
   	 printf("Origin : %d -->",ptr->info);
   	 q = ptr->firstEdge;
   	 while(q != NULL){
   		 printf("%d ,",q->destVertex->info);
   		 q = q->nextEdge;
   	 }
   	 printf("\n");
   	 ptr = ptr->nextVertex;
    }
}

int degreeNode(int u){
    int count = 0;
    VERTEX *locu;
    EDGE *ptr;
    locu = findVertex(u);
    ptr = locu->firstEdge;
    while(ptr != NULL){
   	 count++;
   	 ptr = ptr->nextEdge;
    }
    locu = start;
    while(locu != NULL){
   	 ptr = locu->firstEdge;
   	 while(ptr != NULL){
   		 if(ptr->destVertex->info == u){
   			 count++;
   			 ptr = ptr->nextEdge;
   		 }
   	 }
   	 locu = locu->nextVertex;
    }
    return count;
}

