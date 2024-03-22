#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool cmp(string a, string b){
	if(a.length() != b.length()){
		return a.length() > b.length();
	}
	return a < b;
}

int main() {
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string a[n];
		for(int i=0; i<n; i++){
			cin >> a[i];
		}
		sort(a, a+n, cmp);
		for(string x : a){
			cout << x << " " ;
		}
	}
	return 0;
}
 
 

