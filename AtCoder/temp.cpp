#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 5e3 + 10, MOD = 1e9 + 7;

int n;
ll dp[MAXN][MAXN];
string s;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> s;
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      dp[i][j] = (dp[i - 1][max(j - 1, 0)] + (dp[i - 1][j + 1]  << 1) % MOD) % MOD;
    }
  }
  cout << dp[n][s.size()];
  return 0;
}