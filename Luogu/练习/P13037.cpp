#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10, MOD = 1e9 + 7;

int n, a[MAXN];
vector<int> pos[MAXN];
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

ll solve(int l, int r, int x) {
  if (l > r) return 1;
  int mid = upper_bound(pos[x].begin(), pos[x].end(), r) - pos[x].begin();
  if (!mid) return 0;
  mid = pos[x][mid - 1];
  if (mid < l) return 0;
  return solve(l, mid - 1, x) * solve(mid + 1, r, x + 1) % MOD * C(r - l, mid - l) % MOD;
}

void Solve(int t) {
  cin >> n;
  for (int i = 1; i <= n; pos[i++].clear());
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]].push_back(i);
  }
  cout << "Case #" << t << ": " << solve(1, n, 1) << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  init(MAXN - 1);
  int T, t = 0;
  for (cin >> T; T--; Solve(++t));
  return 0;
}