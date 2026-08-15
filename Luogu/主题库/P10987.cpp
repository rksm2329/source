#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXV = 1e3 + 10, MAXN = 2e2 + 10;

int n, p, q, a[MAXN], dp[MAXV][MAXV];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> p >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int k = 1; k <= n; k++) {
    for (int i = p; i >= 0; i--) {
      for (int j = q; j >= 0; j--) {
        if (i >= a[k]) {
          dp[i][j] = max(dp[i][j], dp[i - a[k]][j] + a[k]);
        }
        if (j >= a[k]) {
          dp[i][j] = max(dp[i][j], dp[i][j - a[k]] + a[k]);
        }
        ans = max(ans, dp[i][j]);
      }
    }
  }
  cout << ans;
  return 0;
}