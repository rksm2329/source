#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 5;

int n, cnt, ans;
vector<int> g[MAXN];

void dfs(int u, int fa) {
  cnt++;
  for (int i = 0; i < g[u].size(); i++) {
    if (g[u][i] != fa) {
      dfs(g[u][i], u);
    }
  }
}

int main() {
  cin >> n;
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }
  for (int i = 0; i < g[1].size(); i++) {
    cnt = 0, dfs(g[1][i], 1);
    ans = max(ans, cnt);
  }
  cout << n - ans << '\n';
  return 0;
}
