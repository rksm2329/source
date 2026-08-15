#include <bits/stdc++.h>

using namespace std;

const int MAXN = 11;

int n, q[MAXN], a[MAXN], b[MAXN], ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> q[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }
  for (int i = 0; i <= 1000000; ++i) {
    int res = INT_MAX;
    for (int j = 1; j <= n; ++j) {
      if (1ll * a[j] * i > q[j]) {
        res = -i;
        break;
      }
      res = min(res, (!b[j] ? INT_MAX : (q[j] - a[j] * i) / b[j]));
    }
    ans = max(ans, res + i);
  }
  cout << ans;
  return 0;
}