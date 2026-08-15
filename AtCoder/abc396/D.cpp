#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 9e18;

struct Edge {
  ll v, w;
};

int n, m;
ll ans = INF;
bool vis[15];
vector<Edge> g[15];

void dfs(int u, ll res) {
  if (vis[u]) {
    return;
  }
  if (u == n) {
    ans = min(ans, res);
    return;
  }
  vis[u] = 1;
  for (Edge e : g[u]) {
    dfs(e.v, res ^ e.w);
  }
  vis[u] = 0;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (ll i = 1, u, v, w; i <= m; i++) {
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  dfs(1, 0);
  cout << ans;
  return 0;
}