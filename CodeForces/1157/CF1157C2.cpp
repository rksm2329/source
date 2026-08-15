#include <iostream>

using namespace std;

const int MAXN = 2e5 + 10;

int n,a[MAXN],l,r,last;
string ans,ans1,ans2;

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (l = 1, r = n; l <= r && a[l] != a[r] && max(a[l], a[r]) > last;){
		if (a[l] < a[r] && a[l] > last || a[r] <= last){
			ans += 'L';
			last = a[l++];
		}
		else {
			ans += 'R';
			last = a[r--];
		}
	}
	ans1 = ans2 = ans;
	for (int i = l, c = last; i <= r && a[i] > c;){
		ans1 += 'L';
		c = a[i++];
	}
	for (int i = r, c = last; i >= l && a[i] > c;){
		ans2 += 'R';
		c = a[i--];
	}
	int len = max(ans1.size(),ans2.size());
	cout << len << '\n' << (ans1.size() > ans2.size() ? ans1 : ans2);
	return 0;
}