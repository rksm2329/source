#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MAXN = 1e5 + 10;

long long n, q, v, a[MAXN];

signed main() {
  cin >> n >> q >> v;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int x, y; q--; ) {
    cin >> x >> y;
    a[x] = y;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (a[i] >= v);
  }
  cout << ans;
  return 0;
}