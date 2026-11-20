#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 3e5 + 10;
const ll INF = 1e18;

ll n, m, k, d;
vector<int> lsh;

struct Node {
  int l, r, v;
} a[MAXN];

struct SegTree {
  ll dat[MAXN << 2], tag[MAXN << 2];
  #define mid (l + r >> 1)
  #define lc root << 1
  #define rc root << 1 | 1
  #define LC lc, l, mid
  #define RC rc, mid + 1, r
  void build(int root, int l, int r) {
    tag[root] = 0;
    if (l == r) {
      dat[root] = d * (lsh[l - 1] - 1);
      return;
    }
    build(LC), build(RC);
    dat[root] = max(dat[lc], dat[rc]);
  }
  void down(int root) {
    if (!tag[root]) return;
    tag[lc] += tag[root], dat[lc] += tag[root];
    tag[rc] += tag[root], dat[rc] += tag[root];
    tag[root] = 0;
  }
  void update(int root, int l, int r, int L, int R, ll val) {
    if (L > R) return;
    if (L <= l && R >= r) {
      dat[root] += val, tag[root] += val;
      return;
    }
    down(root);
    if (L <= mid) update(LC, L, R, val);
    if (R > mid) update(RC, L, R, val);
    dat[root] = max(dat[lc], dat[rc]);
  }
  ll query(int root, int l, int r, int L, int R) {
    if (L <= l && R >= r) return dat[root];
    if (L > r || R < l) return -INF;
    down(root);
    return max(query(LC, L, R), query(RC, L, R));
  }
} T;

int rnk(int x) {
  return lower_bound(lsh.begin(), lsh.end(), x) - lsh.begin() + 1;
}

void Solve() {
  cin >> n >> m >> k >> d;
  lsh = {1};
  for (int i = 1; i <= m; i++) {
    auto &[l, r, v] = a[i];
    cin >> r >> l >> v;
    l = r - l + 1;
    lsh.push_back(l);
    lsh.push_back(r);
    lsh.push_back(r + 1);
  }
  sort(a + 1, a + m + 1, [](const Node &x, const Node &y) { return x.r < y.r; });
  sort(lsh.begin(), lsh.end());
  lsh.erase(unique(lsh.begin(), lsh.end()), lsh.end());
  int w = lsh.size();
  T.build(1, 1, w);
  ll dp = 0;
  for (int i = 1, j = 1; i <= m; i = j) {
    auto &[l, r, v] = a[i];
    for (j = i; j <= m && a[j].r == r; j++) {
      auto [_l, _r, _v] = a[j];
      _l = rnk(_l), T.update(1, 1, w, 1, _l, _v);
    }
    int lf = max(1ll, r - k + 1), L = rnk(lf), R = rnk(r);
    ll ndp = max(dp, T.query(1, 1, w, L, R) - d * r), delta = ndp - dp;
    dp = ndp;
    int u = rnk(r + 2);
    if (delta) T.update(1, 1, w, u, w, delta);
  }
  cout << dp << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int c, T;
  for (cin >> c >> T; T--; Solve());
  return 0;
}