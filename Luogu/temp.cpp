#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAXN = 2e5 + 10;
const ll INF = 2e18;

ll n, a[MAXN];

void Solve() {
  cin >> n;
  for (int i = 1; i <= n; cin >> a[i++]);
  ll ans = 0;
  for (int i = 2; i <= n; i++) ans += abs(a[i] - a[i - 1]);
  ll mx1 = -INF, mx2 = -INF, res = 0;
  for (int r = 2; r < n; r++) {
    mx1 = max(mx1, a[r - 1] - abs(a[r - 1] - a[r]));
    mx2 = max(mx2, -a[r - 1] - abs(a[r - 1] - a[r]));
    res = max(res, abs(a[r] - a[1]) - abs(a[r] - a[r + 1]) + max(mx1 - a[r + 1], mx2 + a[r + 1]));
  }
  ll mn = INF;
  for (int i = 1; i < n; i++) mn = min(mn, abs(a[i] - a[i + 1]));
  res = max(res, abs(a[n] - a[1]) - mn);
  cout << ans + res << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  for (cin >> T; T--; Solve());
  return 0;
}