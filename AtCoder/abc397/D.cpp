#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using i128 = __int128;

const ll MAXV = 1e13;

ll n;

i128 Find(i128 x) {
  i128 l = 0, r = MAXV;
  while (l < r) {
    i128 mid = (l + r + 1) >> 1;
    if (mid * mid <= x) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  return l;
}

bool Solve(i128 a, i128 b, i128 c) {
  i128 delta = b * b - 4 * a * c;
  i128 k = Find(delta);
  if (k * k == delta) {
    i128 t = -b + k;
    if (t > 0 && t % (a << 1) == 0) {
      ll y = t / (a << 1), x = y + a / 3;
      cout << x << ' ' << y;
      return 1;
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (ll i = 1; i * i * i <= n; i++) {
    if (Solve(i * 3, 3 * i * i, i * i * i - n)) {
      return 0;
    }
  }
  cout << -1;
  return 0;
}