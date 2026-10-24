#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 2e5 + 10, INF = 2e9;

struct Node {
  int u, w;
  bool operator<(const Node &oth) const {
    return w > oth.w;
  }
};

int n, m, s, t, dis[MAXN];
vector<pii> g[MAXN];
bool vis[MAXN];

void dij() {
  priority_queue<Node> pq;
  fill(dis + 1, dis + n + 1, INF);
  dis[s] = 0, pq.push({s, 0});
  while (!pq.empty()) {
    auto [u, now] = pq.top(); pq.pop();
    for (auto &[v, w] : g[u]) {
      if (dis[v] > now + w) {
        dis[v] = now + w, pq.push({v, dis[v]});
      }
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> s >> t;
  for (int i = 1, u, v; i <= m; i++) {
    cin >> u >> v;
    g[u].push_back({v, 1});
  }
  for (int i = 1; i <= n; i++) {
    if (g[i].empty()) continue;
    sort(g[i].begin(), g[i].end());
    g[i][0].second = 0;
  }
  dij();
  cout << (dis[t] == INF ? -1 : dis[t]);
  return 0;
}