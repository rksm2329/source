#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n, d, v[MAXN], a[MAXN];

int main() {
  cin >> n >> d;
  for (int i = 1; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int mi = a[1];
	int sum = 0;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		mi = min(mi, a[i]);
		if (sum >= v[i]) {
			sum -= v[i];
			continue;
		}
		int t = (v[i] - sum + d - 1) / d;
		ans += 1ll * t * mi;
		sum = t * d + sum - v[i];
	}
	cout << ans;
  return 0;
}