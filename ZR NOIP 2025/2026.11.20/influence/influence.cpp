#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e7 + 10, MOD = 1e9 + 7;

ll n, m, fac[MAXN], inv[MAXN];

ll qpow(ll x, ll y) {
  ll res = 1;
  for (; y; y >>= 1, (x *= x) %= MOD) {
    if (y & 1) (res *= x) %= MOD;
  }
  return res;
}

void init(int n) {
  fac[0] = fac[1] = inv[0] = inv[1] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
  inv[n] = qpow(fac[n], MOD - 2);
  for (int i = n; i > 1; i--) inv[i - 1] = inv[i] * i % MOD;
}

ll C(int n, int m) {
  return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

int main() {
  freopen("influence.in", "r", stdin);
  freopen("influence.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  init(MAXN - 1);
  // (n * (n - 1) / 2 - n)! / (m - n)! / (n * (n - 1) / 2 - m)!
  ll res = 1;
  for (ll i = n * (n - 1) / 2 - m + 1; i <= n * (n - 1) / 2 - n; i++) (res *= i % MOD) %= MOD;
  cout << res * inv[m - n] % MOD * fac[n - 1] % MOD;
  return 0;
}