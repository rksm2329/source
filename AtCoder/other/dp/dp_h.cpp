#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 10;
const int MOD = 1e9 + 7;

int n, m;
int a[MAXN][MAXN], dp[MAXN][MAXN];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      a[i][j] = c == '#';
    }
  }
  dp[0][1] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!a[i][j]) dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
    }
  }
  cout << dp[n][m];
  return 0;
}