#include <stdio.h>
#include <string.h>

int getPos(char labels[], int ln, char c){
	int i;
	for(i = 0;i < ln;i++){
		if(c == labels[i]){
			return i;
		}
	}
	return -1;
}

int checkFinal(int arr[], int n, int state){
	int i;
	for(i = 0;i < n;i++){
		if(arr[i] == state){
			return 1;
		}
	}
	return 0;
}

int main(){
	int states, initial, currentState = 0, i, j, ln, final, finalNo, checked = 0;
	printf("Enter the number of states : ");
	scanf("%d",&states);
	printf("Enter the number of final state : ");
	scanf("%d",&finalNo);
	int finalArr[finalNo];
	for(i = 0;i < finalNo;i++){
		printf("Enter the final state : ");
		scanf("%d",&finalArr[i]);
	}
	printf("Enter The Number of labels : ");
	scanf("%d",&ln);
	char labels[ln];
	for(i = 0;i < ln;i++){
		scanf(" %c",&labels[i]);
	}
	int transaction[states][ln];
	for(i = 0;i < states;i++){
		for(j = 0;j < ln;j++){
			printf("Edge from %d with %c to : ",i,labels[j]);
			scanf("%d",&transaction[i][j]);
		}
	}
	char input[100];
	while(1){
	printf("Enter the string : ");
	scanf("%s",&input);
	int x= 0, z = strlen(input);
	while(x!=z){
		int pos = getPos(labels, ln, input[x]);
		if(pos == -1){
			printf("REJECTED\n");
			break;
		}
		printf("State q%d -> State q%d\n",currentState,transaction[currentState][pos]);
		currentState = transaction[currentState][pos];
		x++;
		if(currentState == -1){
			printf("Rejected");
			checked = 1;
			break;
		}	
	}
	if(!checked){
	if(checkFinal(finalArr, finalNo, currentState)){
		printf("Accepted\n");
	}else{
		printf("Rejected\n");
	}
	}
	checked = 0;
	currentState = 0;
	}
}
	
