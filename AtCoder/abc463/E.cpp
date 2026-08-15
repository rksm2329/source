#include <bits/stdc++.h>
#define int ll

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 2e5 + 10;
const ll INF = 1e18;

struct Node {
  int u;
  ll t;
  bool operator<(const Node &oth) const {
    return t > oth.t;
  }
};

int n, m, y, a[MAXN];
bool vis[MAXN];
ll dis[MAXN];
vector<pii> g[MAXN];

void dij() {
  priority_queue<Node> pq;
  pq.push({1, 0});
  fill(dis, dis + n + 1, INF);
  dis[1] = 0;
  while (!pq.empty()) {
    auto [u, t] = pq.top(); pq.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (auto [v, w] : g[u]) {
      if (dis[v] > t + w) {
        dis[v] = t + w;
        pq.push({v, t + w});
      }
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> y;
  for (int i = 1, u, v, w; i <= m; i++) {
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    g[i].push_back({0, a[i]});
    g[0].push_back({i, a[i] + y});
  }
  dij();
  for (int i = 2; i <= n; i++) {
    cout << dis[i] << ' ';
  }
  return 0;
}