#include <bits/stdc++.h>
#define int long long

using namespace std;

const int Mod = 998244353;

int n, m, ans;
map<int, int> cnt;

void dfs (int num1, int num0, int maxx) {
	maxx = max (maxx, num1 - num0);
	if (num1 + num0 == n + m) {
		(ans += maxx) %= Mod;
    cnt[maxx]++;
		return ;
	}
	if (num1 < n) {
		dfs (num1 + 1, num0, maxx);
	} 
	if (num0 < m) {
		dfs (num1, num0 + 1, maxx);
	}
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    dfs (0, 0, INT_MIN);
    cout << ans << '\n';
    for (auto &[key, val] : cnt) cout << key << ' ' << val << '\n';
    return 0;
}
/*
A = {1, 10, 44, 110, 165, 132}

A[1] + A[3] = C(n + m - 1, 2)

A[1] + A[3] + A[5] = C(n + m - 1, 4)

i 为奇数

则 A[1] + A[3] + ... A[i] = C(n + m - 1, i - 1)

i 为偶数

则 A[2] + A[4] + ... A[i] = C(n + m - 1, i - 1)
*/