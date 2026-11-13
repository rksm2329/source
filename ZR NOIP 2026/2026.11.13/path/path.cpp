#include <bits/stdc++.h>
// #define localtest

using namespace std;
using ll = long long;

const int MAXN = 1e3 + 10;

int n, m, a[MAXN];

namespace Subtask2 {
  int dis[MAXN][MAXN], pre[MAXN];
  bool ok[MAXN];
  void Solve() {
    for (int i = 1; i <= n; cin >> a[i++]);
    for (int i = 1; i <= n; i++) {
      int cnt = 0;
      for (int j = 1; j <= n; j++) {
        ok[j] = 0;
        if (a[j] == a[i]) ok[j] = 1, cnt++;
        pre[j] = pre[j - 1] + ok[j];
      }
      if (cnt == 1) {
        for (int j = 1; j <= n; j++) dis[j][i] = i != j;
        continue;
      }
      for (int j = 1; j <= n; j++) {
        dis[j][i] = abs(i - j);
        if (a[i] == a[j]) {
          int k = abs(pre[i - 1] - pre[j - 1]);
          dis[j][i] = min(dis[j][i], min(k, cnt - k) + (i != j));
        } else {
          int pos = lower_bound(pre + j, pre + n + 1, pre[j] + 1) - pre;
          if (pos > n) pos = lower_bound(pre + 1, pre + n + 1, 1) - pre;
          int k = abs(pre[i - 1] - pre[pos - 1]);
          dis[j][i] = min(dis[j][i], min(k, cnt - k) + 1);
          pos = lower_bound(pre + 1, pre + n + 1, pre[j]) - pre;
          if (pos == j) pos = lower_bound(pre + j, pre + n + 1, pre[n]) - pre;
          k = abs(pre[i - 1] - pre[pos - 1]);
          if (j == 16 && i == 1) cout << k << ' ' << abs(abs(j - pos)) << '\n';
          dis[j][i] = min(dis[j][i], min(k, cnt - k) + 1 + min(abs(j - pos), n - abs(j - pos)));
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; cout << dis[i][j++] << ' ');
      cout << '\n';
    }
  }
}

int main() {
  #ifndef localtest
  freopen("path.in", "r", stdin);
  freopen("path.out", "w", stdout);
  #endif
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  if (m == 1) Subtask2::Solve();
  return 0;
}