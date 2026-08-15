#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n;

ll Find(ll x) {
  ll l = 0, r = 2e9;
  while (l < r) {
    ll mid = l + r + 1 >> 1;
    if (mid * mid <= x) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  return l;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  ll ans = 0;
  for (ll i = 1; 1ll << i <= n; i++) {
    ll k = 1ll << i;
    ll p = Find(n / k);
    ans += p + 1 >> 1;
  }
  cout << ans;
  return 0;
}