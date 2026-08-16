#include <bits/stdc++.h>
#define sqr(x) ((x) * (x) % MOD)

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10, MOD = 998244353;

int n, k;
ll a[MAXN], fac[MAXN], inv[MAXN];

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
  cin >> n >> k;
  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    (sum += a[i]) %= MOD;
  }
  ll s1 = sqr(sum), s2 = 0;
  for (int i = 1; i <= n; i++) {
    (s1 = s1 - sqr(a[i]) + MOD) %= MOD;
    (s2 += sqr(a[i])) %= MOD;
  }
  init(n);
  cout << (s2 * C(n - 1, k - 1) + s1 * C(n - 2, k - 2)) % MOD;
  return 0;
}