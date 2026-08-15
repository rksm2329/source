#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

int n, m, a[MAXN], b[MAXN];
long long sumb;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    sumb += b[i];
  }
  double one = m / (sumb * 1.0);
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1) {
      ans += 1.0 * b[i] * one;
    }
  }
  cout << fixed << setprecision(3) << ans;
  return 0;
}