#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int t, n;
int dep[MAXN], s[MAXN];
vector<int> g[MAXN];

void dfs(int u, int fa) {
  dep[u] = dep[fa] + 1;
  s[u] = 1;
  for (int v : g[u]) {
    if (v != fa) {
      dfs(v, u);
      s[u] += s[v];
    }
  }
}

int main() {
  freopen("dfs.in", "r", stdin);
  freopen("dfs.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++) {
    cout << dep[i] << ' ' << n - s[i] + 1 << '\n';
  }
  return 0;
}