#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10, MAXL = 60 * MAXN, MOD = 998244353;

int n, m;
vector<ll> pre;

struct Trie {
  int tot = 1, nxt[2][MAXL], cnt[MAXL];
  ll arr[MAXL];
  vector<ll> dp[MAXL];
  void insert(ll val) {
    int cur = 1;
    cnt[1]++;
    for (int i = 59; ~i; i--) {
      bool k = val >> i & 1;
      if (!nxt[k][cur]) nxt[k][cur] = ++tot;
      cur = nxt[k][cur], cnt[cur]++;
    }
    arr[cur] = val;
  }
  void calcdp(int cur, int bit) {
    dp[cur].assign(cnt[cur] + 1, 0);
    if (bit == -1) return;
    int ls = nxt[0][cur], rs = nxt[1][cur];
    if (ls) calcdp(ls, bit - 1);
    if (rs) calcdp(rs, bit - 1);
    for (int k = 1; k <= cnt[cur]; k++) {
      (dp[cur][k] += k <= cnt[ls] ? dp[ls][k] : (dp[rs][k - cnt[ls]] + pre[bit << 1]) % MOD) %= MOD;
      (dp[cur][k] += k <= cnt[rs] ? dp[rs][k] : (dp[ls][k - cnt[rs]] + pre[bit << 1]) % MOD) %= MOD;
    }
  }
  ll getans(ll x, int cur, int bit, int k, ll high = 0) {
    if (bit == -1) return (arr[cur] ^ x) % MOD;
    int ls = nxt[0][cur], rs = nxt[1][cur];
    ll ans = 0;
    if (x >> bit & 1) {
      ans = (high * pre[bit << 1 | 1] % MOD + (k <= cnt[ls] ? dp[ls][k] : (dp[rs][k - cnt[ls]] + pre[bit << 1]) % MOD)) % MOD;
      if (k <= cnt[rs]) return (ans + getans(x, rs, bit - 1, k, (high << 1) % MOD)) % MOD;
      return (ans + getans(x, ls, bit - 1, k - cnt[rs], (high << 1 | 1) % MOD)) % MOD;
    }
    if (k <= cnt[ls]) return (ans + getans(x, ls, bit - 1, k, (high << 1) % MOD)) % MOD;
    return (ans + getans(x, rs, bit - 1, k - cnt[ls], (high << 1 | 1) % MOD)) % MOD;
  }
} T;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  pre.assign(130, 0), pre[0] = 1;
  for (int i = 1; i < 130; i++) pre[i] = (pre[i - 1] << 1) % MOD;
  for (ll i = 1, x; i <= n; i++) {
    cin >> x;
    T.insert(x);
  }
  T.calcdp(1, 59);
  for (ll l, r, k; m--; ) {
    cin >> l >> r >> k;
    cout << (T.getans(r, 1, 59, k) - (!l ? 0 : T.getans(l - 1, 1, 59, k)) + MOD) % MOD << '\n';
  }
  return 0;
}