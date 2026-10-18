#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;

struct Edge {
  int u, v, w;
  bool operator<(const Edge &oth) const {
    return w < oth.w;
  }
};

int n, m, fa[MAXN], tfa[MAXN];
bool vis[MAXN];
vector<Edge> E;
vector<int> node;

int find(int x) {
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int tfind(int x) {
  return tfa[x] == x ? x : tfa[x] = tfind(tfa[x]);
}

void merge(int u, int v) {
  u = find(u), v = find(v);
  if (u != v) fa[u] = v;
}

void clear(int u) {
  if (vis[u]) return;
  node.push_back(u), vis[u] = 1, tfa[u] = u;
}

int kruskal() {
  sort(E.begin() + 1, E.begin() + m + 1);
  iota(fa + 1, fa + n + 1, 1);
  int ans = 0;
  for (int i = 1, j = 1; i <= m; i++) {
    auto [u, v, w] = E[i];
    if (w != E[i - 1].w) {
      for (; j < i; j++) merge(E[j].u, E[j].v);
      for (int x : node) vis[x] = 0;
      node.clear();
    }
    u = find(u), v = find(v);
    if (u == v) continue;
    clear(u), clear(v);
    u = tfind(u), v = tfind(v);
    u == v ? ans++ : tfa[u] = v;
  }
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  E.resize(m + 1);
  for (int i = 1; i <= m; i++) {
    auto &[u, v, w] = E[i];
    cin >> u >> v >> w;
  }
  cout << kruskal();
  return 0;
}