#include <bits/stdc++.h>
#define id(x, y) ((x) * (w + 1) + y)
#define check(x, y) ((x) >= 0 && (x) <= h && (y) >= 0 && (y) <= w)
#define nxt1(x) ((x) + (h + 1) * (w + 1))
#define nxt2(x) ((x) + 2 * (h + 1) * (w + 1))

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const int MAXN = 1e5 + 10, MAXM = 5e2 + 10;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

struct Node {
  ll u, w;
  bool operator<(const Node &oth) const {
    return w > oth.w;
  }
};

int h, w, n, A, B, C;
pll a[MAXN];
vector<pll> g[MAXM * MAXM * 3];
bool v[MAXM][MAXM], vis[MAXM * MAXM * 3];
ll dis[MAXM][MAXM], ans[MAXM * MAXM * 3];

void bfs() {
  queue<pll> q;
  for (int i = 1; i <= n; i++) q.push(a[i]);
  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (!check(nx, ny) || v[nx][ny] || dis[nx][ny]) continue;
      dis[nx][ny] = dis[x][y] + 1;
      q.push({nx, ny});
    }
  }
}

void dij(int s) {
  memset(ans, 0x3f, sizeof ans);
  ans[s] = 0;
  priority_queue<Node> pq;
  pq.push({s, 0});
  while (!pq.empty()) {
    int u = pq.top().u; pq.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (auto &[v, w] : g[u]) {
      if (ans[v] > ans[u] + w) {
        ans[v] = ans[u] + w;
        pq.push({v, ans[v]});
      }
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> h >> w >> A >> B >> C >> n;
  for (int i = 1; i <= n; i++) {
    auto &[x, y] = a[i];
    cin >> x >> y;
    v[x][y] = 1;
  }
  bfs();
  for (int x = 0; x <= h; x++) {
    for (int y = 0; y <= w; y++) {
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!check(nx, ny)) continue;
        g[id(x, y)].push_back({id(nx, ny), C});
      }
      for (int i = 0; i < 2; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!check(nx, ny)) continue;
        g[nxt1(id(x, y))].push_back({nxt1(id(nx, ny)), A});
      }
      for (int i = 2; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!check(nx, ny)) continue;
        g[nxt2(id(x, y))].push_back({nxt2(id(nx, ny)), A});
      }
      g[id(x, y)].push_back({nxt1(id(x, y)), B});
      g[id(x, y)].push_back({nxt2(id(x, y)), B});
      g[nxt1(id(x, y))].push_back({id(x, y), dis[x][y] * C});
      g[nxt2(id(x, y))].push_back({id(x, y), dis[x][y] * C});
    }
  }
  dij(id(a[1].first, a[1].second));
  cout << ans[id(a[n].first, a[n].second)];
  return 0;
}