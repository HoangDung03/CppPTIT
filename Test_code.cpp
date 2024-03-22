#include<iostream>
#include<bits/stdc++.h>
#include<map>
#include<vector>

using namespace std;

struct sv{
	string ten, lop, ma, ns;
	double gpa;
	
	void in(){
		cout << "--------------------------\n";
		cout << "Ma sinh vien: " << ma << endl;
		cout << "Ten sinh vien: " << ten <<endl;
		cout << "Ten lop: " << lop << endl;
		cout << "Nam sinh: " << ns << endl;
		cout << "Diem GPA: " << fixed << setprecision << gpa << endl;
		cout << "---------------------------\n";
	}
	
	void nhap(){
		cout << "Nhap vao ma sinh vien:"; cin >> ma;
		cout << "Nhap ten sinh vien:";
		cin.ignore();
		getline(cin, ten);
		cout << "Nhap lop:n"; cin >> lop ;
		cout << "Nhap nam sinh:"; cin >> ns;
		cout << "Nhap diem GPA:"; cin >> gpa;
	}
};

void inds(sv a[], int n){
	cout << "Thong tin danh sach sinh vien:\n";
	for(int i=0; i<n; i++){
		a[i].in();
	}
}

void tkma(sv a[], int n){
	string ma; 
	cout << "Nhap ma sinh vien can tim: "; cin >> ma;
	bool found = false;
	for(int i=0; i<n; i++){
		if(a[i].ma.find(ma) != string::npos){
			a[i].in(); 
			found = true;
		}
	}
	if(!found)
		cout << "Khong tim thay sinh vien!\n";
}

void lkgpa(sv a[],int n){
	double res = 0;
	for(int i=0; i<n; i++){
		if(a[i].gpa > res) res = a[i].gpa;
	}
	cout << "Danh sach sv co GPA cao nhat:\n";
	for(int i=0; i<n; i++){
		if(res == a[i].gpa){
			a[i].in();
		}
	}
}

bool cmp1(sv a, sv b){
	return a.gpa > b.gpa;
}

void lkgpa2(sv a[], int n){
	vector<sv> v;
	for(int i=0; i<n; i++){
		if(a[i].gpa >= 5) v.push_back(a[i]);
	}
	sort(v.begin(), v.end(), cmp1);	
	cout << "Danh sach sv co GPA >= 5: \n";
	for(sv x : v)
		x.in();
}

string chuanhoa(string name){
	stringstream ss(name); vector<string> v;
	string token, res = "";
	while(ss >> token){
		v.push_back(token);
	}
	res += v[v.size() - 1];
	for(int i=0; i<v.size()-1; i++) res += v[i];
//	return v[i];
}

bool cmp2(sv a, sv b){
	string ten1 = chuanhoa(a.ten);
	string ten2 = chuanhoa(b.ten);
	return ten1 < ten2; 
}

void sxten(sv a[], int n){
	sort(a, a+n, cmp2);
}

int main() {
	sv a[1000];
	int n;
	while(1){
		cout << "------------MENU------------\n";
		cout << "0. Thoat! ";
		cout << "1. Nhap thong tin sinh vien\n";
		cout << "2. Hien thi toan bo danh sach sinh vien\n";
		cout << "3. Tim kiem sinh vien theo ma\n";
		cout << "4. Liet ke sinh vien co diem gpa cao nhat\n";
		cout << "5. Liet ke cac sinh vien co diem GPA >= 2.5\n";
		cout << "6. Sap xep sinh vien theo ten\n";	
		cout << "Nhap lua chon!\n";	
		int lc; cin >> lc;
		if(lc == 1){
			a[n].nhap();
			++n;
		}
		else if(lc == 2){
			inds(a, n);
		}
		else if(lc == 3){
			tkma(a, n);
		}
		else if(lc == 4){
			lkgpa(a, n);
		}
		else if(lc == 5){
			lkgpa2(a, n);
		}
		else if(lc == 6){
			sxten(a, n);
		}
		else if(lc == 0){
			break;
		}
	}
}
 
 

