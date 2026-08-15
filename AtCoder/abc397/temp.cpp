#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10, MOD = 1e9 + 7;

int t, n, k;
ll f[MAXN], fac[MAXN], inv[MAXN];

void init(int n) {
  f[0] = f[1] = inv[1] = fac[0] = fac[1] = 1;
  for (int i = 2; i <= n; i++) {
    f[i] = f[i - 1] * i % MOD;
    inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    fac[i] = fac[i - 1] * inv[i] % MOD;
  }
}

ll C(int n, int m) {
  return f[n] * fac[m] % MOD * fac[n - m] % MOD;
}

void Solve() {
  cin >> n >> k;
  cout << C(n + k - 1, n - 1) << '\n';
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  init(MAXN - 1);
  for (cin >> t; t--; Solve());
  return 0;
}