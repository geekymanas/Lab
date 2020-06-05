#include <stdio.h>
#include <string.h>

int stack[100];
int top=-1;

void push(int i)
{
	top++;
	stack[top] = i;
}

int pop(){
	return stack[top--];
}	

int getPos(char arr[], int n, char c){
	int i;
	for(i = 0;i < n;i++) {
		if(arr[i] == c){
			return i;
		}
	}	
	return -1;
}

int main(){
	int states, i, j, final, k, paths, inputNo, pos;
	printf("Enter the number of states : ");
	scanf("%d",&states);
	printf("Enter the number of input symbols : ");
	scanf("%d",&inputNo);
	char isa[inputNo];
	for(i = 0;i < inputNo;i++){
		printf("Enter The Symbol : ");
		scanf(" %c",&isa[i]);
	}
	int count[states][inputNo];
	int arr[states][inputNo][states];
	for(i = 0;i < states;i++){
		for(j = 0;j < inputNo;j++){
			printf("Enter the number of paths from q%d with %c : ",i,isa[j]);
			scanf("%d",&paths);
			count[i][j] = paths;
			if(paths > 0){
				for(k = 0;k < paths;k++){
					printf("Enter path:");
					scanf("%d",&arr[i][j][k]);
				}
			}
		}
	}
	printf("Enter the final state : ");
	scanf("%d",&final);
	char input[100];
	printf("Enter the input string : ");
	scanf("%s",&input);
	int way = 0, ps = 0;
	i=0;
	while(i<strlen(input)){
		pos = getPos(isa, inputNo, input[i]);
		if(pos == -1){
			printf("Rejected\n");
			return 2;
		}
		if(count[ps][pos] > 0 && way == 0){
			push(arr[ps][pos][way]);
		}
		i++;
		pos = getPos(isa, inputNo, input[i]);
		ps=arr[ps][pos][way];
		if(i == strlen(input)){
			if(ps == final){
				printf("Accepted\n");
				return 0;
			}
			else{
				ps=pop();
				way++;
				i--;
			}
		} 
	}
	printf("Rejected\n");
}
