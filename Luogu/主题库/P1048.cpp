#include <iostream>

using namespace std;

const int MAXN = 1e2 + 10, MAXT = 1e3 + 10;

int t, m, a[MAXN], b[MAXN], dp[MAXN][MAXT];

int main() {
  cin >> t >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= t; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j - a[i] >= 0) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]] + b[i]);
      }
    }
  }
  cout << dp[m][t];

  return 0;
}