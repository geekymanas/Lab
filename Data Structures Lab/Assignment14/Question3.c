#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define TEMP 0
#define PERM 1
#define infinity 999999
#define NIL -1
struct edge {
    int u;
    int v;
};
typedef struct edge EDGE;
int n;
int predecessor[MAX];
int adj[MAX][MAX];
int status[MAX];
int length[MAX];
void make_tree(int r, EDGE tree[MAX]);
void create_graph();
int min_temp();

int main(){
    int i, root, wt_tree = 0;
    EDGE tree[MAX];
    create_graph();
    printf("Enter root vertex\n");
    scanf("%d",&root);
    make_tree(root, tree);
    for(i = 1;i < n;i++){
   	 printf("%d->",tree[i].u);
   	 printf("%d->",tree[i].v);
   	 wt_tree+=adj[tree[i].u][tree[i].v];
    }
    printf("Weight of spanning tree is %d\n",wt_tree);
}

void create_graph(){
    int n, maxEdges, i, origin, destination, wt;
    printf("Enter number of vertex : ");
    scanf("%d",&n);
    maxEdges = n*(n-1)/2;
    for(i = 1;i <=maxEdges;i++){
   	 printf("Enter origin and destination\n");
   	 scanf("%d%d",&origin,&destination);
   	 if(origin == -1 || destination == -1){
   		 break;
   	 }
   	 printf("Enter weight of edge\n");
   	 scanf("%d",&wt);
   	 if(origin>= n || destination >= n || origin < 0 || destination < 0){
   		 printf("Enter proper values\n");
   		 i--;
   	 }else {
   		 adj[origin][destination] = wt;
   		 adj[destination][origin] = wt;
   	 }
    }
}

int min_temp(){
    int i, min = MAX,k = -1;
    for(i = 1;i < MAX;i++){
   	 if(status[i] == TEMP && length[i] < min){
   		 min = length[i];
   		 k = i;
   	 }
    }
    return k;
}

void make_tree(int r, EDGE tree[MAX]){
    int current, i;
    int count = 0;
    for(i = 0;i < n;i++){
   	 predecessor[i] = NIL;
   	 length[i] = infinity;
   	 status[i] = TEMP;
    }
    current = min_temp();
    if(current == NIL){
   	 if(count == n-1){
   		 return;
   	 }else {
   		 printf("The Graph is not connected\n");
   		 exit(1);
   	 }
    }
    status[current] = PERM;
    if(current != r){
   	 count++;
   	 tree[count].u = predecessor[current];
   	 tree[count].v = current;
    }
    for(i = 0;i < n;i++){
   	 if(adj[current][i] > 0 && status[i] == TEMP){
   		 if(adj[current][i] < length[i]){
   			 predecessor[i] = current;
   			 length[i] = adj[current][i];
   		 }
   	 }
    }
}

