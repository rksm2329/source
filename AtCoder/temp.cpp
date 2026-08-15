#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2.5e5 + 10, MOD = 998244353;

int n, q, a[MAXN], cnt[MAXN], s, ans[MAXN], inv[MAXN];
ll fac[MAXN], sum[MAXN], prod[MAXN], res[MAXN];

ll qpow(ll x, ll y) {
  ll res = 1;
  for (; y; y >>= 1, (x *= x) %= MOD) {
    if (y & 1) (res *= x) %= MOD;
  }
  return res;
}

struct Query {
  int l, r, x, id;
  bool operator<(const Query &oth) const {
    int ba = (l - 1) / s + 1;
    int bb = (oth.l - 1) / s + 1;
    if (ba != bb) return ba < bb;
    return ba & 1 ? r < oth.r : r > oth.r;
  }
};

void add(int x) {
  int bx = (x - 1) / s + 1;
  cnt[x]++, sum[bx]++;
  (res[x] *= inv[cnt[x]]) %= MOD;
  (prod[bx] *= inv[cnt[x]]) %= MOD;
}

void del(int x) {
  int bx = (x - 1) / s + 1;
  (res[x] *= cnt[x]) %= MOD;
  (prod[bx] *= cnt[x]) %= MOD;
  cnt[x]--, sum[bx]--;
}

ll qprod(int x) {
  ll sna = 1;
  int bx = (x - 1) / s + 1;
  for (int i = 1; i < bx; i++) (sna *= prod[i]) %= MOD;
  for (int i = (bx - 1) * s + 1; i <= x; i++) (sna *= res[i]) %= MOD;
  return sna;
}

int qcnt(int x) {
  int sna = 0, bx = (x - 1) / s + 1;
  for (int i = 1; i < bx; i++) sna += sum[i];
  for (int i = (bx - 1) * s + 1; i <= x; i++) sna += cnt[i];
  return sna;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> q;
  for (int i = 1; i <= n; cin >> a[i++]);
  vector<Query> qry(q);
  for (int i = 0; i < q; i++) {
    auto &[l, r, x, id] = qry[i];
    cin >> l >> r >> x, id = i;
  }
  s = sqrt(n);
  sort(qry.begin(), qry.end());
  fac[0] = 1;
  for (int i = 1; i <= n; i++) {
    inv[i] = qpow(i, MOD - 2);
    fac[i] = fac[i - 1] * i % MOD;
  }
  fill(res + 1, res + n + 1, 1);
  fill(prod + 1, prod + (n - 1) / s + 2, 1);
  int L = 1, R = 0;
  for (auto &[l, r, x, id] : qry) {
    for (; L > l; add(a[--L]));
    for (; R < r; add(a[++R]));
    for (; L < l; del(a[L++]));
    for (; R > r; del(a[R--]));
    ans[id] = fac[qcnt(x - 1)] * qprod(x - 1) % MOD;
  }
  for (int i = 0; i < q; cout << ans[i++] << '\n');
  return 0;
}