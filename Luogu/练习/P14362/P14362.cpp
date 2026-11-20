#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 1e4 + 20;
const ll INF = 1e18;

struct Edge {
  int u, v, w;
  bool operator<(const Edge &oth) const {
    return w < oth.w;
  }
};

int n, m, k, a[15][MAXN], fa[MAXN], sz[MAXN];
vector<Edge> e, emin, town[15];

int find(int x) {
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}

bool merge(int u, int v) {
  u = find(u), v = find(v);
  if (sz[u] > sz[v]) swap(u, v);
  if (u != v) {
    fa[u] = v, sz[v] += sz[u];
    return 1;
  }
  return 0;
}

void merge(vector<Edge> &now, vector<Edge> oth) {
  vector<Edge> res;
  for (int i = 0, j = 0; i < now.size(); i++) {
    for (; j < oth.size() && oth[j] < now[i]; res.push_back(oth[j++]));
    res.push_back(now[i]);
  }
  now.swap(res);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 1, u, v, w; i <= m; i++) {
    cin >> u >> v >> w;
    e.push_back({u, v, w});
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j <= n; j++) {
      cin >> a[i][j];
      if (j) town[i].push_back({i + n + 1, j, a[i][j]});
    }
    sort(town[i].begin(), town[i].end());
  }
  iota(fa + 1, fa + n + 1, 1);
  fill(sz + 1, sz + n + 1, 1);
  sort(e.begin(), e.end());
  for (auto &[u, v, w] : e) {
    if (merge(u, v)) {
      emin.push_back({u, v, w});
    }
  }
  ll ans = INF;
  for (int S = 0; S < 1 << k; S++) {
    ll sum = 0;
    vector<Edge> now = emin;
    for (int i = 0; i < k; i++) {
      if (S >> i & 1) {
        sum += a[i][0];
        merge(now, town[i]);
      }
    }
    iota(fa + 1, fa + n + k + 1, 1);
    fill(sz + 1, sz + n + k + 1, 1);
    for (auto &[u, v, w] : now) sum += merge(u, v) * w;
    ans = min(ans, sum);
  }
  cout << ans;
  return 0;
}