#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 3e5 + 10;

int n, a[MAXN];
ll dp[MAXN][4], ans;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; cin >> a[i++]);
  dp[2][0] = a[1] < a[2];
  for (int i = 3; i <= n; i++) {
    if (a[i - 2] < a[i - 1] && a[i] < a[i - 1]) {
      dp[i][1] = dp[i - 1][0], dp[i][3] = dp[i - 1][2];
    } else if (a[i - 2] > a[i - 1] && a[i] > a[i - 1]) {
      dp[i][0] = 1, dp[i][2] = dp[i - 1][0], dp[i][3] = dp[i - 1][1];
    } else {
      dp[i][0] = dp[i - 1][0] + (a[i - 1] < a[i]), dp[i][1] = dp[i - 1][1];
      dp[i][2] = dp[i - 1][2], dp[i][3] = dp[i - 1][3];
    }
    ans += dp[i][3];
  }
  cout << ans;
  return 0;
}