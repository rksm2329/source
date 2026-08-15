#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 5e5 + 10;

int n, p[MAXN];
string s;
pair<ll, ll> a[MAXN];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> s;
  int m = 0;
  s = '#' + s;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') {
      p[++m] = i;
    }
  }
  for (int i = 1; i <= m; i++) {
    a[i].first = p[i] - i;
    a[i].second = n - m + i - p[i];
  }
  for (int i = 1; i <= m; i++) {
    a[i].first += a[i - 1].first;
  }
  for (int i = m; i >= 1; i--) {
    a[i].second += a[i + 1].second;
  }
  ll ans = 2e18;
  for (int i = 0; i <= m; i++) {
    ans = min(ans, a[i].first + a[i + 1].second);
  }
  cout << ans;
  return 0;
}