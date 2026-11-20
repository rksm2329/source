#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1.1e5;

int n, k;
ll ans[MAXN], pre[MAXN][125];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> k;
  int b = 120;
  for (int i = 1, x, l, d; i <= k; i++) {
    cin >> x >> l >> d;
    if (d > b) {
      for (; l--; ans[x + l * d]++);
    } else pre[x][d]++, pre[x + l * d][d]--;
  }
  for (int d = 1; d <= b; d++) {
    for (int i = d; i <= n; i++) pre[i][d] += pre[i - d][d];
    for (int i = 1; i <= n; i++) ans[i] += pre[i][d];
  }
  for (int i = 1; i <= n; cout << ans[i++] << ' ');
  return 0;
}