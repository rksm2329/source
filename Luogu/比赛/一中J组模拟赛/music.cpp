#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll t, n, m;

void Solve() {
  cin >> n >> m;
  ll ans1 = m;
  ll ans2;
  if (m <= n) {
    ans2 = (m > 0);
  } else {
    ans2 = max(m / n, m % n);
  }
  cout << ans1 << ' ' << ans2 << '\n';
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("music.in", "r", stdin);
  freopen("music.out", "w", stdout);
  for (cin >> t; t--; Solve()) {
  }
  return 0;
}