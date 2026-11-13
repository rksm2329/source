#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e6 + 10, INF = 1e9;

int n, dp[MAXN][2][3];
string a, b;

int main() {
  freopen("nung.in", "r", stdin);
  freopen("nung.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> a >> b;
  a = '#' + a, b = '#' + b;
  fill(&dp[0][0][0], &dp[n][1][2] + 1, INF);
  dp[0][0][0] = 0;
  for (int i = 1; i <= n; i++) {
    bool u = a[i] - '0', v = b[i] - '0';
    if (u == v) {
      for (int p : {0, 1}) {
        for (int q : {0, 1, 2}) {
          dp[i][0][0] = min(dp[i][0][0], dp[i - 1][p][q]);
          dp[i][1][(u ^ 1) + 1] = min(dp[i][1][(u ^ 1) + 1], dp[i - 1][p][q] + (!p) + (q != (u ^ 1) + 1));
          dp[i][0][u + 1] = min(dp[i][0][u + 1], dp[i - 1][p][q] + (q != u + 1));
        }
      }
    } else {
      for (int p : {0, 1}) {
        for (int q : {0, 1, 2}) {
          dp[i][1][0] = min(dp[i][1][0], dp[i - 1][p][q] + (!p));
          dp[i][0][(u ^ 1) + 1] = min(dp[i][0][(u ^ 1) + 1], dp[i - 1][p][q] + (q != (u ^ 1) + 1));
          dp[i][1][u + 1] = min(dp[i][1][u + 1], dp[i - 1][p][q] + (!p) + (q != u + 1));
        }
      }
    }
  }
  int ans = INF;
  for (int p : {0, 1}) {
    for (int q : {0, 1, 2}) ans = min(ans, dp[n][p][q]);
  }
  cout << ans;
  return 0;
}