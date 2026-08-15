#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10, MAXV = 35;

struct Edge {
  int v, w;
};

int n, m, flag, color[MAXN], ans[MAXN];
vector<Edge> g[MAXN];
vector<int> res[2];

void dfs(int u, int nowcol, int k) {
  if (color[u] != -1) {
    flag |= color[u] != nowcol;
    return;
  }
  color[u] = nowcol;
  res[nowcol].push_back(u);
  for (Edge e : g[u]) {
    dfs(e.v, (e.w >> k & 1 ? nowcol ^ 1 : nowcol), k);
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 1, u, v, w; i <= m; i++) {
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  for (int k = MAXV - 1; k >= 0; k--) {
    fill(color + 1, color + n + 1, -1);
    for (int i = 1; i <= n; i++) {
      if (color[i] == -1) {
        res[0].clear(), res[1].clear();
        dfs(i, 0, k);
        if (res[0].size() < res[1].size()) {
          swap(res[0], res[1]);
        }
        for (int u : res[1]) {
          ans[u] |= 1 << k;
        }
      }
    }
  }
  if (flag) {
    cout << -1;
  } else {
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << ' ';
    }
  }
  return 0;
}