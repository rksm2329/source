#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;

int n, a[MAXN], p[MAXN], fa[MAXN], sz[MAXN], dfn[MAXN], top[MAXN], son[MAXN], dep[MAXN], f[MAXN], ts;
ll dp[MAXN];
vector<int> g[MAXN];

void dfs1(int u, int fa) {
  sz[u] = 1, dep[u] = dep[fa] + 1, f[u] = fa;
  for (int v : g[u]) {
    if (v == fa) continue;
    dfs1(v, u), sz[u] += sz[v];
    if (sz[v] > sz[son[u]]) son[u] = v;
  }
}

void dfs2(int u, int ftop) {
  dfn[u] = ++ts, top[u] = ftop;
  if (son[u]) dfs2(son[u], ftop);
  for (int v : g[u]) {
    if (v == son[u] || v == f[u]) continue;
    dfs2(v, v);
  }
}

int lca(int u, int v) {
  for (; top[u] != top[v]; u = f[top[u]]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
  }
  return dep[u] < dep[v] ? u : v;
}

int dis(int u, int v) {
  return dep[u] + dep[v] - (dep[lca(u, v)] << 1);
}

int find(int x) {
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p[a[i]] = fa[i] = i;
  }
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs1(1, 0), dfs2(1, 1);
  for (int i = 1; i <= n; i++) {
    int u = p[i];
    for (int v : g[u]) {
      if (a[v] < i) {
        v = find(v);
        dp[u] = max(dp[u], dp[v] + dis(u, v));
        fa[v] = u;
      }
    }
  }
  cout << dp[p[n]];
  return 0;
}