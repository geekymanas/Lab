#include <stdlib.h>
#include <stdio.h>
#define MAX 100
#define NIL -1
struct edge {
    int u;
    int v;
    struct edge *next;
    int weight;
}*front = NULL;
typedef struct edge EDGE;
void insert(int i, int j, int wt);
EDGE* delete();
void makeTree(EDGE tree[MAX]);
void createGraph();
int n;

int main(){
    int i;
    EDGE tree[MAX];
    int wt_tree = 0;
    createGraph();
    makeTree(tree);
    for (int i = 0; i < n; ++i)
    {
   	 printf("%d->",tree[i].u);
   	 printf("%d ",tree[i].v);
   	 wt_tree+=tree[i].weight;
    }
    printf("Weight of min spanning tree is : ",wt_tree);
}

void insert(int i, int j, int wt){
    EDGE *q, *temp;
    temp = (EDGE*) malloc(sizeof(EDGE));
    temp->u = i;
    temp->v = j;
    temp->weight = wt;
    temp->next = NULL;
    if(front == NULL || temp->weight < front->weight){
   	 temp->next = front;
   	 front = temp;
    }else {
   	 q = front;
   	 while(q != NULL && q->weight <= temp->weight){
   		 q = q->next;
   	 }
   	 temp->next = q->next;
   	 q->next = temp;
   	 if(q->next == NULL){
   		 temp->next = NULL;
   	 }
    }
}

EDGE* delete(){
    EDGE *temp;
    temp = front;
    front = front->next;
    return temp;
}

void makeTree(EDGE tree[MAX]){
    int v1, v2, i, count = 0, root_v1, root_v2;
    EDGE *temp;
    int father[n];
    for(i = 0;i < n;i++){
   	 father[i] = NIL;
    }
    while(front != NULL){
   	 temp = delete();
   	 v1 = temp->u;
   	 v2 = temp->v;
   	 while(v1 != NIL){
   		 root_v1 = v1;
   		 v1 = father[v1];
   	 }
   	 while(v2 != NIL){
   		 root_v2 = v2;
   		 v2 = father[v2];
   	 }
   	 if(root_v2 != root_v1){
   		 count++;
   		 tree[count].u = temp->u;
   		 tree[count].v = temp->v;
   		 tree[count].weight = temp->weight;
   		 father[root_v2] = root_v1;
   	 }
    }
    if(count < n-1){
   	 printf("The Graph is not connected\n");
   	 exit(1);
    }
}

void createGraph(){
    int i, wt, maxEdge, origin, destination;
    printf("Enter number of vertices : ");
    scanf("%d",&n);
    maxEdge = n*(n-1)/2;
    for(i = 1;i <= maxEdge;i++){
   	 printf("Enter values of origin and destination\n");
   	 if(origin == -1 || destination == -1){
   		 break;
   	 }else {
   		 printf("Enter The weight of this edge\n");
   		 scanf("%d",&wt);
   		 if(origin >= n || destination >= n || origin < 0 || destination < 0){
   			 printf("Not proper vertices\n");
   			 i--;
   		 }else {
   			 insert(origin, destination, wt);
   		 }
   	 }
    }
}

