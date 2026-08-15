#include<iostream>
#include<cmath>

using namespace std;

int a[110];

bool isprime(int n){
	if (n == 1) return 0;
	for (int i = 2; i <= sqrt(n); i++){
		if (n % i == 0) return 0;
	}
	return true;
}

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		if (isprime(a[i])){
			cout << a[i] << ' ';
		}
	}
	return 0;
}