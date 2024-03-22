#include<iostream>

using namespace std;

struct rectangle{
	float m, n;
};

void nhap(rectangle a[], int n){
	for(int i=0; i<n; i++){
		cin >> a[i].m >> a[i].n;
	} 
}

void xuat(rectangle a[], int n){
	for(int i=0; i<n; i++){
		cout << a[i].m*a[i].n << endl;
	}
}
int main() {
	struct rectangle ds[50];
	int N;
	cin >> N;
	nhap(ds, N);
	xuat(ds, N);
	return 0;
}
 
 

