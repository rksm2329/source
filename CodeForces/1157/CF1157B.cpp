#include<iostream>

using namespace std;

const int MAXN = 2e5 + 10;

int n,f[10],p,a[MAXN];

char ch;

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> ch;
		a[i] = ch - '0';
	}
	for (int i = 1; i <= 9; i++){
		cin >> f[i];
	}
	for (p = 0; p < n && f[a[p]] <= a[p]; p++){
	}
	for (; p < n && f[a[p]] >= a[p]; p++){
		a[p] = f[a[p]];
	}
	for (int i = 0; i < n; i++){
		cout << a[i];
	}
	return 0;
}