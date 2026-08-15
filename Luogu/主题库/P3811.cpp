#include<iostream>

using namespace std;

const int MAXN = 3e6 + 10;

int n,p,a[MAXN];

int main(){
	cin >> n >> p;
    cout << 1 << '\n';
    a[1] = 1;
	for (int i = 2; i <= n; i++){
		a[i] = 1ll * (p - p / i) * a[p % i] % p;
        cout << a[i] << '\n';
	}
	return 0;
}