#include <stdio.h>
#include <stdlib.h>
#define initial 1
#define visited 2
#define waiting 3
int adj[100][100];
int n;
int dist, origin;
int stack[100];
int top = -1;
int state[100];
int queue[100];
int front = -1, rear = -1;

void enque(int i){
	if(rear == 99){
    	printf("No Space\n");
    	return;
	}
	if(front == -1){
    	front = 0;
	}
	rear++;
	queue[rear] = i;
}

int deque(){
	int del_item;
	if(front == -1 || front > rear){
    	printf("No elements\n");
    	exit(1);
	}
	del_item = queue[front];
	front--;
	return del_item;
}

void BFS(int v){
	int i;
	enque(v);
	while(front != -1 || front < rear){
    	v = deque();
    	printf("%d",v);
    	state[v] = visited;
    	for(i = 0;i < n;i++){
        	if(adj[v][i] == 1 && state[v] == initial){
            	enque(i);
            	state[i] = waiting;
        	}
    	}  
	}
	printf("\n");
}


void bfs_traversal(){
	int v;
	for(v = 0;v < n;v++){
    	state[v] = initial;
	}
	printf("Enter The vertice to start the travesal\n");
	scanf("%d",&v);
	BFS(v);
	for(v = 0;v < n;v++){
    	if(state[v] == initial){
        	BFS(v);
    	}
	}
}


void push(int i){
	if(top == 99){
    	printf("Stack overflow");
    	return;
	}
	top++;
	stack[top] = i;
}

int pop(){
	int v;
	if(top == -1){
    	printf("underflow");
    	exit(1);
	}
	else {
    	v = stack[top];
    	top--;
    	return v;
	}

}

void DFS(int v){
	int i;
	push(v);
	while(top != -1){
    	v = pop();
    	if(state[v] == initial){
        	printf("%d ", v);
        	state[v] = visited;
    	}
    	for(i = n-1;i>=0;i--){
        	if(adj[v][i] == 1 && state[i] == initial){
            	push(i);
        	}
    	}
	}
}

void dfs_traversal(){
	int v;
	for(v = 0;v < n;v++){
    	state[v] = initial;
	}
	printf("Enter the starting node for traversal\n");
	scanf("%d",&v);
	DFS(v);
	for(v = 0;v < n;v++){
    	if(state[v] == 0){
        	DFS(v);
    	}
	}
}

void createGraph(){
	int i, maxEdges = n*(n-1);
	for(i = 1;i <=maxEdges;i++){
    	printf("Enter The origin and destination\n");
    	scanf("%d%d",&origin,&dist);
    	if(origin==-1 || dist == -1){
        	break;
    	}
    	if(origin>=n || dist >=n || origin < 0 || dist < 0){
        	printf("Invalid Option\n");
        	i--;
    	}
    	else {
        	adj[origin][dist] = 1;
    	}
	}
}

void deleteEdge(){
	if(origin>= n || dist>= 0 || origin < 0 || dist < 0){
    	printf("Invalid option\n");
    	return;
	}
	if(adj[origin][dist] != 0) {
    	adj[origin][dist] = 0;
	}
}

void insertEdge(){
	if(origin >= n || origin < 0 || dist < 0 || dist >= n){
    	printf("Invalid Option\n");
    	return;
	}
	adj[origin][dist] = 1;
}
void display(){
	int i, j;
	for(i = 0;i < n;i++){
    	for(j = 0;j < n;j++){
        	printf("%4d",adj[i][j]);
    	}
    	printf("\n");
	}
}
int main() {
	int choice;
	printf("Enter Number of vertices : ");
	scanf("%d",&n);
	createGraph();
	while(1){
        	printf("1.Insert Edge\n2.Delete Edge\n3.Display DFS\n4.Display BFS\n5.Exit\n");
        	scanf("%d",&choice);
        	switch(choice){
        	case 1:
            	printf("Enter edge origin and destination\n");
            	scanf("%d%d",&origin,&dist);
            	insertEdge();
            	break;
        	case 2:
            	printf("Enter origin and destination of edge to be deleted\n");
            	scanf("%d%d",&origin,&dist);
            	deleteEdge();
            	break;
        	case 3:
            	dfs_traversal();
            	break;
        	case 4:
            	bfs_traversal();
            	break;
        	case 5:
                	return 1;
        	default:
            	printf("Enter valid option\n");
        	}
	}
}

