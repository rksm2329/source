#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 5e5 + 10, INF = 1e9;

struct SegTree {
  int tag[MAXN << 2];
  #define mid (l + r >> 1)
  #define lc root << 1
  #define rc root << 1 | 1
  #define LC lc, l, mid
  #define RC rc, mid + 1, r
  void update(int root, int l, int r, int L, int R, int val) {
    if (L > R) return;
    if (L <= l && R >= r) {
      tag[root] = max(tag[root], val);
      return;
    }
    if (L <= mid) update(LC, L, R, val);
    if (R > mid) update(RC, L, R, val);
  }
  int query(int root, int l, int r, int pos) {
    if (l == r) return tag[root];
    return max(tag[root], pos <= mid ? query(LC, pos) : query(RC, pos));
  }
} T;

int n, m, L[MAXN], R[MAXN], ind[MAXN], pos[MAXN];
int pre[MAXN], suf[MAXN];
vector<int> g[MAXN];
vector<pii> E;

void chkmin(pii &ans, pii k) {
  if (k.second < ans.second) ans = k;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  E.reserve(m);
  for (int i = 1, u, v; i <= m; i++) {
    cin >> u >> v;
    ind[v]++, g[u].push_back(v);
    E.push_back({u, v});
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (!ind[i]) q.push(i);
  }
  vector<int> topo;
  topo.reserve(n);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    topo.push_back(u);
    for (int v : g[u]) {
      if (!--ind[v]) q.push(v);
    }
  }
  for (int i = 0; i < n; i++) pos[topo[i]] = i + 1;
  for (int u : topo) {
    for (int v : g[u]) L[v] = max(L[v], L[u] + 1);
  }
  reverse(topo.begin(), topo.end());
  for (int u : topo) {
    for (int v : g[u]) R[u] = max(R[u], R[v] + 1);
  }
  reverse(topo.begin(), topo.end());
  for (int i = 1; i <= n; i++) pre[i] = max(pre[i - 1], L[topo[i - 1]]);
  for (int i = n; i >= 1; i--) suf[i] = max(suf[i + 1], R[topo[i - 1]]);
  for (auto &[u, v] : E) {
    T.update(1, 1, n, pos[u] + 1, pos[v] - 1, L[u] + R[v] + 1);
  }
  pii ans = {0, INF};
  for (int i = 1; i <= n; i++) {
    int x = topo[i - 1];
    int val = max({pre[i - 1], suf[i + 1], T.query(1, 1, n, pos[x])});
    chkmin(ans, {x, val});
  }
  cout << ans.first << ' ' << ans.second;
  return 0;
}