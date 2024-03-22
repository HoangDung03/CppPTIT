#include<stdio.h> 
int main(){ 
	int n; 
	scanf("%d",&n); 
	
	while (n>10) { 
	scanf("%d",&n); 
	}
	for(int i=0;i<n;i++){ 
		long long a; 
		scanf("%lld",&a); 
		printf("%.0Lf\n",(1+a)*(long double)a/2); 
	} 
	return 0; 
}
 

