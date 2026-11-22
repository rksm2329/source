#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 3e5 + 10;

ll n, dp[MAXN][4], pre[MAXN][4], last[3];
string s;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> s;
  s = '#' + s, dp[0][0] = 1, pre[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    last[s[i] - 'A'] = i;
    for (int j = 1; j < 4; j++) {
      int mi = min({last[0], last[1], last[2]}) - 1;
      if (mi < 0) continue;
      dp[i][j] = pre[mi][j - 1];
    }
    for (int j = 0; j < 4; j++) pre[i][j] = pre[i - 1][j] + dp[i][j];
  }
  cout << dp[n][3];
  return 0;
}