#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e3 + 10;
const ll INF = 2e12;

int n, m;
ll a[MAXN][MAXN], l[MAXN][MAXN], r[MAXN][MAXN], u[MAXN][MAXN], d[MAXN][MAXN];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      l[i][j] = max(a[i][j], l[i][j - 1] + a[i][j]);
    }
    for (int j = m; j >= 1; j--) {
      r[i][j] = max(a[i][j], r[i][j + 1] + a[i][j]);
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      u[i][j] = max(a[i][j], u[i - 1][j] + a[i][j]);
    }
    for (int i = n; i >= 1; i--) {
      d[i][j] = max(a[i][j], d[i + 1][j] + a[i][j]);
    }
  }
  ll ans = -INF;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      ans = max({ans, l[i][j] + d[i][j] - a[i][j], d[i][j] + r[i][j] - a[i][j], r[i][j] + u[i][j] - a[i][j], u[i][j] + l[i][j] - a[i][j], l[i][j] + r[i][j] - a[i][j]});
    }
  }
  cout << ans;
  return 0;
}