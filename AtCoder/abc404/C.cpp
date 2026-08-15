#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;

int n, m, deg[MAXN];
vector<int> g[MAXN];
bool vis[MAXN];

void dfs(int u) {
  if (vis[u]) {
    return;
  }
  vis[u] = 1;
  for (int v : g[u]) {
    dfs(v);
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    deg[u]++, deg[v]++;
  }
  if (m != n) {
    cout << "No";
    return 0;
  }
  dfs(1);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (deg[i] != 2 || !vis[i]) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}