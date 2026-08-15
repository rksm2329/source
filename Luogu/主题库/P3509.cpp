#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e6 + 10;
const ll INF = 1e18;

int n, k, f[2][MAXN], ans[MAXN];
ll m, a[MAXN];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> k >> m;
  for (int i = 1; i <= n; cin >> a[i++]);
  int l = 1, r = k + 1;
  f[0][1] = k + 1, ans[1] = m & 1 ? f[0][1] : 1;
  for (int i = 2; i <= n; i++) {
    for (; r + 1 <= n && a[r + 1] - a[i] < a[i] - a[l]; l++, r++);
    f[0][i] = a[i] - a[l] < a[r] - a[i] ? r : l;
    ans[i] = m & 1 ? f[0][i] : i;
  }
  for (int k = 1; k <= 60; k++) {
    for (int i = 1; i <= n; i++) {
      f[k & 1][i] = f[k - 1 & 1][f[k - 1 & 1][i]];
    }
    if (m >> k & 1) {
      for (int i = 1; i <= n; i++) ans[i] = f[k & 1][ans[i]];
    }
  }
  for (int i = 1; i <= n; cout << ans[i++] << ' ');
  return 0;
}