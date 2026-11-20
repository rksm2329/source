#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 1e5 + 10;
const ll INF = 1e18;

struct Node {
  ll u, w;
  bool operator<(const Node &oth) const {
    return w > oth.w;
  }
};

int n, m, h, a[MAXN];
ll dis[2][MAXN];
bool vis[MAXN];
vector<pii> g[MAXN], kg[MAXN];
priority_queue<Node> pq;

void dij(int s) {
  fill(dis[0] + 1, dis[0] + n + 1, INF);
  fill(vis + 1, vis + n + 1, 0);
  pq.push({s, 0}), dis[0][s] = 0;
  while (!pq.empty()) {
    auto [u, now] = pq.top(); pq.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (auto &[v, w] : kg[u]) {
      if (dis[0][v] > now + (w << 1)) {
        dis[0][v] = now + (w << 1);
        pq.push({v, now + (w << 1)});
      }
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> h;
  for (int i = 1; i <= n; cin >> a[i++]);
  for (int i = 1, u, v, w; i <= m; i++) {
    cin >> u >> v >> w;
    if (a[u] >= w) {
      g[u].push_back({v, w});
      kg[v].push_back({u, w});
    }
    if (a[v] >= w) {
      g[v].push_back({u, w});
      kg[u].push_back({v, w});
    }
  }
  dij(n);
  fill(dis[1] + 1, dis[1] + n + 1, INF);
  fill(vis + 1, vis + n + 1, 0);
  pq.push({1, 0}), dis[1][1] = 0;
  ll ans = INF;
  while (!pq.empty()) {
    auto [u, now] = pq.top(); pq.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    ll nowh = h - now;
    if (u == n) ans = min(ans, now + a[n] - nowh);
    if (nowh <= 0) {
      ans = min(ans, now + dis[0][u] + a[n] - nowh);
      continue;
    }
    for (auto &[v, w] : g[u]) {
      ll nh = min(nowh - w, (ll)a[v]), nd = now + nowh - nh;
      if (dis[1][v] > nd) dis[1][v] = nd, pq.push({v, nd});
    }
  }
  cout << (ans == INF ? -1 : ans);
  return 0;
}