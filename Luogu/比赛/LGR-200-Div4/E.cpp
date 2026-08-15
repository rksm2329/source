#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e2 + 10;

int n, m, a[MAXN][MAXN];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int op, x, y, c; m; m--) {
    cin >> op >> x >> y >> c;
    if (op == 1) {
      a[x][y] += c;
    } else {
      a[x][y] -= c;
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        mx = max(mx, a[i][j]);
      }
    }
    cout << mx << '\n';
  }
  return 0;
}