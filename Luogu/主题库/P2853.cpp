#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 10, MAXK = 1e2 + 10;

int k, n, m, x[MAXK];
bool vis[MAXN];
int v[MAXN];
vector<int> g[MAXN];

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
  cin >> k >> n >> m;
  for (int i = 1; i <= k; i++) {
    cin >> x[i];
  }
  for (int i = 1, u, v; i <= m; i++) {
    cin >> u >> v;
    g[u].push_back(v);
  }
  for (int i = 1; i <= k; i++) {
    fill(vis + 1, vis + n + 1, 0);
    dfs(x[i]);
    for (int j = 1; j <= n; j++) {
      v[j] += vis[j];
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (v[i] == k);
  }
  cout << ans;
  return 0;
}