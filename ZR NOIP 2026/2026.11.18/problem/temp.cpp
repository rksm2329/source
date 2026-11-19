#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 5e3 + 10;

int n, a[MAXN];

int main() {
  freopen("1.in", "r", stdin);
  freopen("brute.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; cin >> a[i++]);
  ll ans = 0;
  for (int l = 1; l <= n; l++) {
    int mx = a[l];
    for (int r = l + 1; r <= n; r++) {
      mx = max(mx, a[r]);
      ans += mx * ((a[l] & a[r]) == min(a[l], a[r]));
    }
  }
  cout << ans;
  return 0;
}