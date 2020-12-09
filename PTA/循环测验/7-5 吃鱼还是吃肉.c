#include<stdio.h>
int main(){
	int N,gen[11],sta[11],wei[11];
	scanf("%d",&N);
	int temp = N;
	int i = 0,ssta,swei;
	while(temp--){
		scanf("%d %d %d",&gen[i],&sta[i],&wei[i]);
		i++;
	}
	for(i = 0;i < N;i++){
		if(gen[i] == 1){
			ssta = 130;
			swei = 27; 
		} 
		else{
			ssta = 129;
			swei = 25;
		}
		if(sta[i] == ssta)
			printf("wan mei!");
		else if(sta[i] < ssta)
			printf("duo chi yu!");
		else
			printf("ni li hai!");
				
		if(wei[i] == swei)
			printf(" wan mei!\n");
		else if(wei[i] < swei)
			printf(" duo chi rou!\n");
		else
			printf(" shao chi rou!\n");
	
	}
}
