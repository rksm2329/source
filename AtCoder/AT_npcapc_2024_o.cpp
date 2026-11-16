
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 1e4 + 10, MAXM = 1e6 + 10, MOD = 19260817;

int n, m, fa[MAXN << 1], sz[MAXN << 1], sum, pre[MAXN];
ll dp[MAXN];
bool inst0[MAXN << 1];
pii req[MAXM], cnt[MAXN << 1];
pair<bool, int> ndp[MAXN];

int find(int x) {
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int u, int v) {
  u = find(u), v = find(v);
  if (sz[u] > sz[v]) swap(u, v);
  if (u == v) return;
  fa[u] = v, sz[v] += sz[u];
  cnt[v].first += cnt[u].first;
  cnt[v].second += cnt[u].second;
}

void del(int w) {
  if (!w) return;
  for (int i = w; i <= n; i++) {
    dp[i] = (dp[i] - dp[i - w] + MOD) % MOD;
  }
}

void add(int w) {
  if (!w) return;
  for (int i = n; i >= w; i--) {
    dp[i] = (dp[i] + dp[i - w]) % MOD;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    auto &[u, v] = req[i];
    cin >> u >> v;
  }
  int V = n << 1;
  iota(fa + 1, fa + 2 * V + 1, 1);
  fill(sz + 1, sz + 2 * V + 1, 1);
  for (int i = 1; i <= V; cnt[i++].first = 1);
  for (int i = V + 1; i <= V << 1; cnt[i++].second = 1);
  dp[0] = 1;
  for (int i = 1; i <= V; i++) add(1);
  for (int i = m; i >= 1; i--) {
    auto [u,v] = req[i];
    if (find(u) == find(v) || find(u) == find(v + V)) continue;
    auto &[c0u, c1u] = cnt[find(u)];
    auto &[c0v, c1v] = cnt[find(v)];
    del(abs(c0u - c1u)), del(abs(c0v - c1v));
    int c0 = c0u + c1v, c1 = c1u + c0v;
    add(abs(c0 - c1));
    sum += min(c0, c1) - (min(c0u, c1u) + min(c0v, c1v));
    if (dp[n - sum]) merge(u, v + V), merge(u + V, v);
    else {
      del(abs(c0 - c1));
      sum -= min(c0, c1);
      c0 = c0u + c0v, c1 = c1u + c1v;
      add(abs(c0 - c1));
      sum += min(c0, c1);
      merge(u, v), merge(u + V, v + V);
    }
  }
  int target = n - sum;
  ndp[0] = {1, 0};
  for (int i = 1; i <= (V << 1); i++) {
    if (find(i) != i) continue;
    int j = find(i <= V ? i + V : i - V);
    if (i > j) continue;
    int root = cnt[i].first <= cnt[i].second ? i : j;
    int w = abs(cnt[root].first - cnt[root].second);
    inst0[root] = 1;
    if (!w) continue;
    for (int k = target; k >= w; k--) {
      if (!ndp[k].first && ndp[k - w].first) {
        ndp[k] = {1, root}, pre[k] = k - w;
      }
    }
  }
  for (int k = target; k; k = pre[k]) {
    int r = ndp[k].second;
    inst0[r] = 0;
    int s = find(r <= V ? r + V : r - V);
    inst0[s] = 1;
  }
  for (int i = 1; i <= V; cout << inst0[find(i++)]);
  return 0;
}