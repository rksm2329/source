#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e6 + 10;

int n, m, a[MAXN];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 1, l, r; i <= m; i++) {
    cin >> l >> r;
    a[l]++, a[r + 1]--;
  }
  int ans = m;
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
    ans = min(ans, a[i]);
  }
  cout << ans;
  return 0;
}