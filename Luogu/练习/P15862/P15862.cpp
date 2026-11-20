#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 110, MOD = 998244353;

ll n, k, p[2], nxt[MAXN], dp[MAXN][MAXN][MAXN], ans;
string s;

void DP(vector<int> &path, int v) {
  memset(dp, 0, sizeof dp);
  dp[1][2][v] = 1;
  for (int i = 1; i < k; i++) {
    for (int x = 1; x <= (k << 1 | 1); x++) {
      for (int y = 1; y <= (k << 1 | 1); y++) {
        if (!dp[i][x][y]) continue;
				for (int q : {0, 1}) {
          for (int r : {0, 1}) {
            if (x == 1 && q == 0 || x == (k << 1 | 1) && q == 1) continue;
            if (y == 1 && r == 0 || y == (k << 1 | 1) && r == 1) continue;
            int p1 = x == 1 ? 1 : p[q ^ 1];
            int p2 = y == 1 ? 1 : p[r ^ 1];
            int nx = x + (q ? 1 : -1), ny = y + (r ? 1 : -1);
            if (s[path[nx]] != s[path[ny]]) continue;
            (dp[i + 1][nx][ny] += dp[i][x][y] * p1 % MOD * p2 % MOD) %= MOD;
          }
        }
      }
    }
  }
  for (int i = 1; i <= (k << 1 | 1); i++) {
    (ans += dp[k][v - 1][i] * (v == 2 ? 1 : p[0]) % MOD + dp[k][v + 1][i] * p[1] % MOD) %= MOD;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> k >> p[0] >> s;
  s = '#' + s;
  p[1] = MOD + 1 - p[0];
  for (int i = 1; i <= n; cin >> nxt[i++]);
  for (int u = 1; u <= n; u++) {
    vector<int> path;
    path.push_back(0);
    int now = u;
    for (int i = 1; i <= (k << 1 | 1); i++) {
      path.push_back(now), now = nxt[now];
    }
    for (int i = 1; i < path.size(); i++) {
      if (s[path[i]] == s[path[2]]) DP(path, i);
    }
  }
  cout << ans;
  return 0;
}