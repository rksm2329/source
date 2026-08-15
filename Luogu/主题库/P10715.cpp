#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 5e2 + 10;
const int INF = 5e8 + 10;

int t, n, a[MAXN], c[MAXN], dp[MAXN][MAXN][MAXN];

void Solve() {
  cin >> n;
  int q = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    q += (a[i] %= 2);
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  fill(&dp[0][0][0], &dp[n + 1][n + 1][n + 1], INF);
  dp[0][0][0] = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        dp[i + 1][j][k + j % 2] = min(dp[i + 1][j][k + j % 2], dp[i][j][k] + c[i + 1] * a[i + 1]);
        dp[i + 1][j + 1][k + !(j % 2)] = min(dp[i + 1][j + 1][k + !(j % 2)], dp[i][j][k] + c[i + 1] * !a[i + 1]);
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    if (dp[n][q][i] != INF) {
      cout << dp[n][q][i] << ' ';
    } else {
      cout << -1 << ' ';
    }
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  for (cin >> t; t--; Solve());
  return 0;
}