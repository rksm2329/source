#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;

struct Node {
  ll u, w;
  bool op;
  bool operator<(const Node &oth) const {
    return w > oth.w;
  }
};

int n, m, x;
ll dis[MAXN][2];
bool vis[MAXN][2];
vector<int> g[MAXN][2];

void dij() {
  priority_queue<Node> pq;
  for (int i = 1; i <= n; i++) {
    dis[i][0] = dis[i][1] = 2e18;
  }
  for (dis[1][0] = 0, pq.push({1, 0, 0}); !pq.empty(); ) {
    Node now = pq.top();
    pq.pop();
    if (vis[now.u][now.op]) {
      continue;
    }
    vis[now.u][now.op] = 1;
    for (int v : g[now.u][now.op]) {
      if (now.w + 1 < dis[v][now.op]) {
        dis[v][now.op] = now.w + 1;
        pq.push({v, now.w + 1, now.op});
      }
    }
    for (int v : g[now.u][!now.op]) {
      if (now.w + x + 1 < dis[v][!now.op]) {
        dis[v][!now.op] = now.w + x + 1;
        pq.push({v, now.w + x + 1, !now.op});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> x;
  for (int i = 1, u, v; i <= m; i++) {
    cin >> u >> v;
    g[u][0].push_back(v);
    g[v][1].push_back(u);
  }
  dij();
  cout << min(dis[n][0], dis[n][1]);
  return 0;
}