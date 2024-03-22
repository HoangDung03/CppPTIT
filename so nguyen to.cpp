#include<bits/stdc++.h>
 using namespace std; 
 using ll = long long; 
 int ktr(int n){ 
   for(int i =2;i<=sqrt(n);i++){
    if(n%i==0) return false; 
 } 
 	return n>1;
 } 
 	int main(){ 
	 ll n; 
	 cin>>n; 
	 if(ktr(n)==0) cout<<"NO"; 
	 else cout<<"YES"; }
 
 

