#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10, MAXL = 60 * MAXN, MOD = 998244353;

struct Trie {
  int tot, nxt[2][MAXL], cnt[MAXL];
  ll arr[MAXL];
  void insert(ll val) {
    int cur = 0;
    for (int i = 60; ~i; i--) {
      bool k = val >> i & 1;
      if (!nxt[k][cur]) nxt[k][cur] = ++tot;
      cur = nxt[k][cur], cnt[cur]++;
    }
    arr[cur] = val;
  }
  ll find(int cur, int bit, ll val, int k) {
    if (bit == -1) return arr[cur] ^ val;
    bool now = val >> bit & 1;
    if (nxt[now][cur] && cnt[nxt[now][cur]] >= k) return find(nxt[now][cur], bit - 1, val, k);
    else return find(nxt[now ^ 1][cur], bit - 1, val, k - cnt[nxt[now][cur]]);
  }
} T;

int n, m;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (ll i = 1, x; i <= n; i++) {
    cin >> x;
    T.insert(x);
  }
  for (ll l, r, k; m--; ) {
    cin >> l >> r >> k;
    ll ans = 0;
    for (ll i = l; i <= r; i++) (ans += T.find(0, 60, i, k)) %= MOD;
    cout << ans << '\n';
  }
  return 0;
}