#include<iostream>

using namespace std;

int n,cnt;

int f(int x){
	for (x++;x % 10 == 0; x /= 10){
	}
	return x;
}

int main(){
	cin >> n;
	while (n > 9){
		cnt++;
		n = f(n);
	}
	cout << cnt + 9;
	return 0;
}