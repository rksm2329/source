
#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int MAXN = 2e5 + 10;

int n, a[MAXN], pre[MAXN][5], sz[MAXN], dp[MAXN][5];
pii rc[5];

void Solve() {
  cin >> n;
  int cnt = 0, ans = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sz[i] = cnt;
    for (int j = 0; j < cnt; j++) {
      int p = pre[i][j] = rc[j].second;
      dp[i][j] = 0;
      if (a[p] == a[i]) continue;
      dp[i][j] = 2;
      for (int k = 0; k < sz[p]; k++) {
        int q = pre[p][k];
        if (!dp[p][k] || a[q] == a[i]) continue;
        dp[i][j] = max(dp[i][j], dp[p][k] + 1);
      }
      ans = max(ans, dp[i][j]);
    }
    int pos = -1;
    for (int j = 0; j < cnt; j++) if (rc[j].first == a[i]) pos = j;
    if (~pos) {
      for (int j = pos; j < cnt - 1; j++) rc[j] = rc[j + 1];
      cnt--;
    }
    for (int j = min(cnt, 4); j > 0; j--) rc[j] = rc[j - 1];
    rc[0] = {a[i], i};
    cnt = min(cnt + 1, 5);
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  for (cin >> T; T--; Solve());
  return 0;
}
