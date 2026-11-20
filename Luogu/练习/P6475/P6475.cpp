#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 3e5 + 10, MOD = 998244353;

int m, n, x, y;
ll fac[MAXN], inv[MAXN];

ll qpow(ll x, ll y) {
  ll res = 1;
  for (; y; y >>= 1, (x *= x) %= MOD) {
    if (y & 1) (res *= x) %= MOD;
  }
  return res;
}

void init(int n) {
  fac[0] = fac[1] = inv[0] = inv[1] = 1;
  for (int i = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * i % MOD;
  }
  inv[n] = qpow(fac[n], MOD - 2);
  for (int i = n; i > 1; i--) {
    inv[i - 1] = inv[i] * i % MOD;
  }
}

ll C(int n, int m) {
  return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> m >> n >> x >> y;
  init(m + n * 2);
  if (y <= n) {
    ll ans = 0;
    for (int h = 1; h <= m; h++) {
      (ans += C(h + x - 2, x - 1) * C(m - h + n - y, n - y) % MOD * C(m + n - 1, n) % MOD) %= MOD;
    }
    cout << ans;
  } else if (x <= n && y >= n) {
    ll ans = 0;
    for (int h = 1; h <= m; h++) {
      (ans += C(h + x - 2, x - 1) * C(m - h + n - x, n - x) % MOD * C(m - h + y - n - 1, y - n - 1) % MOD * C(h + n * 2 - y - 1, n * 2 - y) % MOD) %= MOD;
    }
    cout << ans;
  } else {
    ll ans = 0;
    for (int h = 1; h <= m; h++) {
      (ans += C(m + n - 1, n) * C(m - h + x - n - 1, x - n - 1) % MOD * C(h + n * 2 - y - 1, n * 2 - y) % MOD) %= MOD;
    }
    cout << ans;
  }
  return 0;
}