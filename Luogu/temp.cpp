#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;

int n, a[MAXN];
string s;

void Solve() {
  cin >> n;
  for (int i = 1; i <= n; cin >> a[i++]);
  cin >> s;
  s = '#' + s;
  ll ans = 0;
  for (int l = 1; l <= n; l++) {
    pair<int, int> mx = {a[l], l}, mi = {a[l], l};
    for (int r = l + 1; r <= n; r++) {
      if (a[r] > mx.first) mx = {a[r], r};
      if (a[r] < mi.first) mi = {a[r], r};
      ans += s[mx.second] != s[mi.second];
    }
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  for (cin >> T; T--; Solve());
  return 0;
}