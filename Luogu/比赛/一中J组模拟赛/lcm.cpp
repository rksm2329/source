#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int t, x, y;

ll gcd(ll x, ll y) {
  return !y ? x : gcd(y, x % y);
}

ll lcm(ll x, ll y) {
  return x / gcd(x, y) * y;
}

ll W(ll x) {
  ll p = 2e9;
  for (ll i = 2; i * i <= x; i++) {
    if (y % i == 0) {
      p = min({p, i, x / i});
      break;
    }
  }
  return p;
}

void Solve() {
  cin >> x >> y;
  int g = gcd(x, y);
  if (g == 1) {
    ll ans1 = W(x);
    ll ans2 = W(y);
    if (ans1 == ans2 && ans1 == 2e9) {
      cout << lcm(x, y) << '\n';
    } else {
      cout << min(lcm(x, ans2) + y, lcm(y, ans1) + x) << '\n';
    }
  } else {
    if (g == x) {
      cout << y << '\n';
    } else if (g == y) {
      cout << x << '\n';
    } else {
      cout << x + y << '\n';
    }
  }
}

int main() {
  freopen("lcm.in", "r", stdin);
  freopen("lcm.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  for (cin >> t; t--; Solve()) {
  }
  return 0;
}