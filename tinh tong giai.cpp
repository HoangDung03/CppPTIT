#include<bits/stdc++.h> 
using namespace std; 
	int main(){ 
	long long n; 
	cin>>n; 
	long long sum=0; 
	long long tich=1; 
	for(int i=1;i<=n;i++){
	 for(int j=1;j<=i;j++){ 
	 	tich*=j; 
	} 
	sum+=tich; tich=1; 
	} 
	cout<<sum; }
	
 
 

