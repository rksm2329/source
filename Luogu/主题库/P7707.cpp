#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 6e5 + 10;

int n, m, k;
pii a[MAXN];

struct Node {
  int x, lc, rc, cnt;
  bool operator<(const Node &oth) const {
    return x < oth.x;
  }
  Node operator+(const Node &oth) {
    if (!x) return oth;
    if (!oth.x) return *this;
    return {max(x, oth.x), lc, oth.rc, cnt + oth.cnt - (rc == oth.lc)};
  }
};

struct SegTree {
  vector<Node> dat[MAXN << 2];
  Node E;
  #define mid (l + r >> 1)
  #define LC root << 1, l, mid
  #define RC root << 1 | 1, mid + 1, r
  #define lc(x) x << 1
  #define rc(x) x << 1 | 1
  void pushup(int root) {
    vector<Node> now;
    Node ls = E, rs = E;
    for (int i = 0, j = 0; i < dat[lc(root)].size() || j < dat[rc(root)].size(); ) {
      int val;
      if (j == dat[rc(root)].size() || (i < dat[lc(root)].size() && dat[lc(root)][i] < dat[rc(root)][j])) val = dat[lc(root)][i].x;
      else val = dat[rc(root)][j].x;
      if (i < dat[lc(root)].size() && dat[lc(root)][i].x == val) ls = dat[lc(root)][i++];
      if (j < dat[rc(root)].size() && dat[rc(root)][j].x == val) rs = dat[rc(root)][j++];
      now.push_back(ls + rs); 
    }
    dat[root].swap(now);
  }
  void update(int root, int l, int r, int pos, pii val) {
    if (l == r) {
      dat[root] = {{val.first, val.second, val.second, 1}};
      return;
    }
    if (pos <= mid) update(LC, pos, val);
    else update(RC, pos, val);
    if (r == pos) pushup(root);
  }
  Node query(int root, int l, int r, int L, int R, int val) {
    if (L <= l && R >= r) {
      auto it = upper_bound(dat[root].begin(), dat[root].end(), (Node){val, 0, 0, 0});
      return it == dat[root].begin() ? E : *prev(it);
    }
    if (L > r || R < l) return E;
    return query(LC, L, R, val) + query(RC, L, R, val);
  }
} T;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
  }
  int w = n + m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].second;
    T.update(1, 1, w, i, a[i]);
  }
  for (int i = 1, op, ans = 0; i <= m; i++) {
    cin >> op;
    if (op == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      l ^= ans * k, r ^= ans * k, x ^= ans * k;
      cout << (ans = T.query(1, 1, w, l, r, x).cnt) << '\n';
    } else {
      int x, y;
      cin >> x >> y;
      x ^= ans * k, y ^= ans * k;
      T.update(1, 1, w, ++n, {x, y});
    }
  }
  return 0;
}