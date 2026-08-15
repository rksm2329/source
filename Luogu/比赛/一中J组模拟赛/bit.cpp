#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("bit.in", "r", stdin);
  freopen("bit.out", "w", stdout);
  cin >> n;
  ll x = 1;
  ll ans = 0;
  for (; x <= n; x *= 2) {
    ans += (n / x) % 2;
  }
  cout << ans;
  return 0;
}