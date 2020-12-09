#include<stdio.h>

int IsPrimeNum(int x){
	int i = 2;
	while(x % i != 0){
		i++;
	}
	if(x == i) return 1;
	else return 0;
}

int main(){
	int m,i,count = 0;
	scanf("%d",&m);
	for(i = m-1;i > 1;i--){
		if(IsPrimeNum(i)){
			printf("%6d",i);
			count++;
		}
		if(count == 10) break;		
	}
	return 0;	
}

