#include<stdio.h> 
int main(){ \
	int n; 
	scanf("%d", &n); 
	double sum = 0; 
	for(int i = 1; i <= n; i++){ 
		sum += (float)1/ i;
	 } 
	 printf("%0.4f", sum); 
	 
	 return 0;
 }
 
 

