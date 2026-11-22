#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10, INF = 1e9;

int n, m, fir[MAXN], dis[MAXN], cnt[MAXN];
array<int, 3> edge[MAXN];
vector<int> g[MAXN];

void bfs() {
  queue<int> q;
  fill(dis + 1, dis + m + 1, -1);
  for (int id : g[1]) dis[id] = 1, q.push(id);
  while (!q.empty()) {
    int id = q.front(); q.pop();
    auto &[u, v, w] = edge[id];
    if (cnt[v] >= 2 || (cnt[v] && fir[v] == w)) continue;
    cnt[v]++;
    if (cnt[v] == 1) {
      fir[v] = w;
      for (int nid : g[v]) {
        if (edge[nid][2] == w) continue;
        if (dis[nid] == -1) dis[nid] = dis[id] + 1, q.push(nid);
      }
    } else {
      for (int nid : g[v]) {
        if (edge[nid][2] != fir[v]) continue;
        if (dis[nid] == -1) dis[nid] = dis[id] + 1, q.push(nid);
      }
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    auto &[u, v, w] = edge[i];
    cin >> u >> v >> w, g[u].push_back(i);
  }
  bfs();
  int ans = INF;
  for (int i = 1; i <= m; i++) {
    if (edge[i][1] == n && ~dis[i]) ans = min(ans, dis[i]);
  }
  cout << (ans == INF ? -1 : ans);
  return 0;
}