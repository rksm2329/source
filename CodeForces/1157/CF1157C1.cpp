#include<iostream>

using namespace std;

const int MAXN = 2e5 + 10;

int n,a[MAXN];
string ans;

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int l = 1, r = n, last = 0; l <= r && max(a[l],a[r]) > last;){	
		if (a[l] < a[r] && a[l] > last || a[r] <= last){
			ans += 'L';
			last = a[l++];
		}
		else {
			ans += 'R';
			last = a[r--];
		}
	}
	cout << ans.size() << '\n' << ans;
	return 0;
}