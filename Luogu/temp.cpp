#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 5e5 + 10;

int n, m, a[MAXN];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; cin >> a[i++]);
  int ans = 0;
  for (int i = 0; i < 30; i++) {
    sort(a + 1, a + n + 1, [&](const int x, const int y) {
      if ((x >> i & 1) != (y >> i & 1)) return (x >> i & 1) > (y >> i & 1);
      return x > y;
    });
    int res = (1 << 30) - 1;
    for (int j = 1; j <= m; j++) res &= a[j];
    ans = max(ans, res);
  }
  cout << ans;
  return 0;
}