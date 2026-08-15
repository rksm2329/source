#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10, INF = 1e9;

vector<int> g[MAXN];
int n, m, a[MAXN], dfn[MAXN], low[MAXN], ts;
bool flag[MAXN];

void tarjan(int u, int fa) {
  dfn[u] = low[u] = ++ts;
  int cnt = 0;
  for (int v : g[u]) {
    if (v == fa) continue;
    if (dfn[v]) {
      low[u] = min(low[u], dfn[v]);
    } else {
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
      if (~fa && low[v] >= dfn[u]) flag[u] = 1;
      cnt++;
    }
  }
  if (fa == -1 && cnt > 1) flag[u] = 1;
}

void Solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    g[i].clear();
    dfn[i] = low[i] = 0;
    flag[i] = 0;
  }
  ts = 0;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  if (n == 1) {
    cout << a[1] << '\n';
    return;
  }
  tarjan(1, -1);
  int ans = INF;
  for (int i = 1; i <= n; i++) {
    if (!flag[i]) ans = min(ans, a[i]);
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  for (cin >> T; T--; Solve());
  return 0;
}