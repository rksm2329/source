#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 5e5 + 10;

int n, q, sz[MAXN], dep[MAXN], son[MAXN], f[MAXN], top[MAXN], dfn[MAXN], dfm[MAXN], ts;
vector<int> g[MAXN];

void dfs1(int u, int fa) {
  sz[u] = 1, dep[u] = dep[fa] + 1, f[u] = fa;
  for (int v : g[u]) {
    if (v == fa) continue;
    dfs1(v, u);
    sz[u] += sz[v];
    if (sz[v] > sz[son[u]]) son[u] = v;
  }
}

void dfs2(int u, int ftop) {
  dfn[u] = ++ts, dfm[ts] = u, top[u] = ftop;
  if (son[u]) { dfs2(son[u], ftop); }
  for (int v : g[u]) {
    if (v == f[u] || v == son[u]) continue;
    dfs2(v, v);
  }
}

int lca(int u, int v) {
  for (; top[u] != top[v]; u = f[top[u]]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
  }
  if (dep[u] > dep[v]) swap(u, v);
  return u;
}

int dis(int u, int v) {
  return dep[u] + dep[v] - (dep[lca(u, v)] << 1);
}

int get(int u, int v) {
  if (lca(u, v) != u) return f[u];
  else {
    if (lca(v, son[u]) == son[u]) return son[u];
    else {
      for (; f[top[v]] != u; v = f[top[v]]);
      return top[v];
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> q;
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs1(1, 0);
  dfs2(1, 1);
  for (int i = 1, a, b, c; i <= q; i++) {
    cin >> a >> b >> c;
    int ans = n;
    if (dis(a, b) != dis(a, c) + dis(c, b)) {
      cout << "0\n";
      continue;
    }
    if (a != c) {
      int A = get(c, a);
      ans -= A == f[c] ? n - sz[c] : sz[A];
    }
    if (b != c) {
      int B = get(c, b);
      ans -= B == f[c] ? n - sz[c] : sz[B];
    }
    cout << ans << '\n';
  }
  return 0;
}