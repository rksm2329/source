#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int t, n, a[MAXN], dp[MAXN];

void Solve() {
  cin >> n;
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        dp[a[i]] = max({dp[a[i]], dp[j] + 1, dp[a[i] / j] + 1});
      }
    }
    ans = max(ans, dp[a[i]]);
  }
  cout << n - ans << '\n';
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  for (cin >> t; t--; Solve()) {
  }
  return 0;
}