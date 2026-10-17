#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MAXN = 5e5 + 10;
const i64 INF = 4e18;

struct Node {
  i64 u, w;
  bool operator<(const Node &oth) const {
    return w != oth.w ? w < oth.w : u > oth.u;
  }
};

int n, m;
i64 dis[MAXN];
vector<int> g[MAXN];

int jid() {
  priority_queue<Node> pq;
  pq.push({1, 0});
  fill(dis + 2, dis + n + 1, INF);
  int ans = 0;
  while (!pq.empty()) {
    auto [u, nw] = pq.top(); pq.pop();
    if (nw != dis[u]) continue;
    ans++;
    for (int v : g[u]) {
      if (dis[v] > dis[u] + 1) {
        dis[v] = dis[u] + 1, pq.push({v, dis[v]});
      }
    }
  }
  return ans;
}

void Solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; g[i++].clear());
  for (int i = 1, u, v; i <= m; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cout << jid() << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int c, T;
  for (cin >> c >> T; T--; Solve());
  return 0;
}