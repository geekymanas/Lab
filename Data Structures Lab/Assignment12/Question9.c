#define MAX 100
int n, origin, dest;
int adj[MAX][MAX];
int queue[MAX] , front = -1, rear = -1;
void createGraph();
void enque(int info);
int deque();
int Indegree(int v);

void createGraph(){
    int maxEdge, i;
    printf("Enter number of vertices of graph\n");
    scanf("%d",&n);
    maxEdge = n*(n-1);
    for(i = 1;i < maxEdge;i++){
   	 printf("Enter origin and destination\n");
   	 scanf("%d%d",&origin,&dest);
   	 if(origin == -1 || dest == -1){
   		 break;
   	 }
   	 if(origin >= n || dest >= n || origin < 0 || dest < 0){
   		 printf("Enter valid vertices\n");
   		 i--;
   	 }else {
   		 adj[origin][dest] = 1;
   	 }
    }
}

void enque(int info){
    if(rear == MAX-1){
   	 printf("Overflow of queue");
    }else {
   	 if(front == -1){
   		 printf("HEre\n");
   		 front = 0;
   	 }
   	 rear++;
   	 queue[rear] = info;
    }
}
int deque(){
    if(front > rear || front == -1){
   	 printf("No Elements %d %d \n", front , rear);
   	 exit(1);
    }else {
   	 int x = queue[front];
   	 front--;
   	 return x;
    }
}

int Indegree(int v){
    int i, count = 0;
    for(i = 0;i < n;i++){
   	 if(adj[i][v] == 1){
   		 count++;
   	 }
    }
    return count;
}

int main() {
    int i, v, count, indegree[n], topo[MAX];
    createGraph();
    printf("%d",n);
    for(i = 0;i < n;i++){
   	 indegree[i] = Indegree(i);
   	 if(indegree[i] == 0){
   		 enque(i);
   	 }
    }
    count = 0;
    while(front == -1 || front > rear){
   	 v = deque();
   	 topo[++count] = v;
   	 for(i = 0;i < n;i++){
   		 if(adj[v][i] == 1){
   			 indegree[i] = indegree[i] - 1;
   			 if(indegree[i] == 0){
   				 enque(i);
   			 }
   		 }
   	 }
    }
    if(count < n){
   	 printf("No Topological sorting can be made as graph contains cycle\n");
   	 exit(1);
    }
    printf("Vertices in Topological order are \n");
    for(i = 1;i <=count;i++){
   	 printf("%d",topo[i]);
    }
    printf("\n");
} 

