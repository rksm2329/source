#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e6 + 10;
const ll INF = 1e18;

struct SegTree {
  ll dat[MAXN << 2], tag[MAXN << 2];
  #define mid (l + r >> 1)
  #define LC root << 1, l, mid
  #define RC root << 1 | 1, mid + 1, r
  void down(int root) {
    if (!tag[root]) return;
    dat[root << 1] += tag[root];
    dat[root << 1 | 1] += tag[root];
    tag[root << 1] += tag[root];
    tag[root << 1 | 1] += tag[root];
    tag[root] = 0;
  }
  void update(int root, int l, int r, int L, int R, int val) {
    if (L <= l && R >= r) {
      dat[root] += val, tag[root] += val;
      return;
    }
    down(root);
    if (L <= mid) update(LC, L, R, val);
    if (R > mid) update(RC, L, R, val);
    dat[root] = min(dat[root << 1], dat[root << 1 | 1]);
  }
  ll query(int root, int l, int r, int L, int R) {
    if (L > R) return 0;
    if (L <= l && R >= r) return dat[root];
    down(root);
    ll ans = INF;
    if (L <= mid) ans = min(ans, query(LC, L, R));
    if (R > mid) ans = min(ans, query(RC, L, R));
    return ans;
  }
} T;

int n, m, f[MAXN], w[MAXN];
vector<int> pos[MAXN];

void update(int x) {
  if (pos[f[x]].empty()) return;
  T.update(1, 1, n, pos[f[x]].back(), n, -2 * w[f[x]]);
  if (pos[f[x]].size() == 1) return;
  T.update(1, 1, n, pos[f[x]][pos[f[x]].size() - 2], n, w[f[x]]);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; cin >> f[i++]);
  for (int i = 1; i <= m; cin >> w[i++]);
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    update(i);
    T.update(1, 1, n, i, n, w[f[i]]);
    ans = max(ans, T.query(1, 1, n, i, i) - min(T.query(1, 1, n, 1, i - 1), 0ll));
    pos[f[i]].push_back(i);
  }
  cout << ans;
  return 0;
}