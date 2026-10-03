#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 2e5 + 10;

int n, q, dfn[MAXN], low[MAXN], idx, st[MAXN], top, deg[MAXN], dp[MAXN], scc[MAXN], scnt;
bool ins[MAXN];
vector<pii> g[MAXN], ng[MAXN];

void tarjan(int u) {
  dfn[u] = low[u] = ++idx, st[++top] = u, ins[u] = 1;
  for (auto [v, w] : g[u]) {
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (ins[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (dfn[u] == low[u]) {
    ++scnt;
    while (1) {
      int v = st[top--];
      ins[v] = 0;
      scc[v] = scnt;
      if (v == u) break;
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> q;
  for (int i = 1, u, v, w; i <= q; i++) {
    cin >> w >> u >> v;
    g[u].push_back({v, w});
  }
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) tarjan(i);
  }
  for (int u = 1; u <= n; u++) {
    for (auto [v, w] : g[u]) {
      if (scc[u] == scc[v] && w) {
        cout << "No\n";
        return 0;
      }
    }
  }
  for (int u = 1; u <= n; u++) {
    for (auto [v, w] : g[u]) {
      if (scc[u] == scc[v]) continue;
      ng[scc[u]].push_back({scc[v], w});
      deg[scc[v]]++;
    }
  }
  queue<int> qu;
  for (int i = 1; i <= scnt; i++) {
    if (!deg[i]) qu.push(i);
  }
  while (!qu.empty()) {
    int u = qu.front();
    qu.pop();
    for (auto &[v, w] : ng[u]) {
      dp[v] = max(dp[v], dp[u] + w);
      if (!--deg[v]) qu.push(v);
    }
  }
  cout << "Yes\n";
  for (int i = 1; i <= n; i++) {
    cout << dp[scc[i]] + 1 << ' ';
  }
  return 0;
}