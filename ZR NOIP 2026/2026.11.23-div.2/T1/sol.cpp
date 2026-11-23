#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 4e3 + 10, MOD = 998244353;

ll n, dp[3][MAXN][MAXN], len[3];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int _ : {1, 2}) {
    vector<int> v = {0};
    for (int i = _; i <= n; i += 2) {
      v.push_back(i);
      if (i != n) v.push_back(i);
    }
    len[_] = v.size() - 1, dp[_][0][0] = 1;
    for (int i = 1; i <= len[_]; i++) {
      for (int j = 0; j <= i; j++) {
        (dp[_][i][j] += dp[_][i - 1][j]) %= MOD;
        if (v[i] >= j - 1 && j) (dp[_][i][j] += (v[i] - j + 1) * dp[_][i - 1][j - 1] % MOD) %= MOD;
      }
    }
  }
  for (int k = 1; k < n << 1; k++) {
    ll ans = 0;
    for (int i = 0; i <= k; i++) {
      (ans += dp[1][len[1]][i] * dp[2][len[2]][k - i] % MOD) %= MOD;
    }
    cout << ans << ' ';
  }
  return 0;
}