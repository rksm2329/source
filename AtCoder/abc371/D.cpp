#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;

int n, q, a[MAXN], b[MAXN];
ll sum[MAXN];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    sum[i] = sum[i - 1] + b[i];
  }
  cin >> q;
  for (int l, r; q; q--) {
    cin >> l >> r;
    int nl = lower_bound(a + 1, a + n + 1, l) - a;
    int nr = upper_bound(a + 1, a + n + 1, r) - 1 - a;
    cout << sum[nr] - sum[nl - 1] << '\n';
  }
  return 0;
}