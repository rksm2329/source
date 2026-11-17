#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 5e3 + 10, MOD = 998244353;

string s;
int lcp[MAXN][MAXN], lcs[MAXN][MAXN];
ll dp[MAXN][MAXN];

void Solve() {
  cin >> s;
  int n = s.size();
  s = '#' + s;
  fill(&dp[0][0], &dp[n][n] + 1, 0);
  fill(&lcp[0][0], &lcp[n][n] + 1, 0);
  fill(&lcs[0][0], &lcs[n][n] + 1, 0);
  for (int i = n; i >= 1; i--) {
    for (int j = n; j > i; j--) {
      if (s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (s[i] == s[j]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
    }
  }
  for (int l4 = 1; l4 <= n; l4++) {
    for (int l1 = 1; l1 < l4; l1++) {
      int len = lcp[l1][l4];
      if (!len) continue;
      int r1 = min(l4 - 1, l1 + len - 1);
      dp[l1][l4]++, dp[r1 + 1][l4]--;
    }
    for (int l1 = 1; l1 < l4; l1++) (dp[l1][l4] += dp[l1 - 1][l4]) %= MOD;
  }
  for (int l1 = 1; l1 <= n; l1++) {
    for (int l4 = n; l4 > l1; l4--) (dp[l1][l4] += dp[l1][l4 + 1]) %= MOD;
  }
  for (int l4 = 1; l4 <= n; l4++) {
    for (int l1 = 1; l1 < l4; l1++) (dp[l1][l4] += dp[l1 - 1][l4]) %= MOD;
  }
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= n; i++) (dp[i][j] += dp[i - 1][j]) %= MOD;
    for (int i = 1; i <= n; i++) (dp[i][j] += dp[i - 1][j]) %= MOD;
  }
  ll ans = 0;
  for (int r2 = 1; r2 <= n; r2++) {
    for (int r3 = r2 + 1; r3 <= n; r3++) {
      int len = lcs[r2][r3], k = min({len, r3 - r2, r2 - 2});
      if (k <= 0) continue;
      (ans += (dp[r2 - 2][r3 + 1] - dp[r2 - k - 2][r3 + 1] + MOD) % MOD) %= MOD;
    }
  }
  cout << ans << '\n';
}

int main() {
  freopen("ppap.in", "r", stdin);
  freopen("ppap.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int T;
  for (cin >> T; T--; Solve());
  return 0;
}
/*
(l1, l1 + 1)
(r1, l4)
*/