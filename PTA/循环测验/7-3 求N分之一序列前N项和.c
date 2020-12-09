#include<stdio.h>
int main(){
	int N,i,x = 1;
	double res = 0;
	scanf("%d",&N);
	for(i = N;i > 0;i--){
		res += 1.0/x;
		x++;
	}
	printf("sum = %.6lf",res);
}
