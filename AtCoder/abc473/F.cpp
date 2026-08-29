#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 5e5 + 10, INF = 1e9;

struct SegTree {
  int dat[MAXN << 2], tag[MAXN << 2];
  #define mid (l + r >> 1)
  #define lc root << 1
  #define rc root << 1 | 1
  #define LC lc, l, mid
  #define RC rc, mid + 1, r
  void down(int root) {
    if (!tag[root]) return;
    dat[lc] += tag[root];
    dat[rc] += tag[root];
    tag[lc] += tag[root];
    tag[rc] += tag[root];
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
    dat[root] = min(dat[lc], dat[rc]);
  }
  int query(int root, int l, int r, int L, int R) {
    if (L == R && !L) return 0;
    if (L <= l && R >= r) return dat[root];
    down(root);
    int res = INF;
    if (L <= mid) res = min(res, query(LC, L, R));
    if (R > mid) res = min(res, query(RC, L, R));
    return res;
  }
} T;

int n, q, pre[MAXN];
string s;

int value(char c) {
  return c == 'A' ? 1 : -1;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> s >> q;
  s = '#' + s;
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + value(s[i]);
    T.update(1, 1, n, i, i, pre[i]);
  }
  for (int i = 1, op; i <= q; i++) {
    cin >> op;
    if (op == 1) {
      int x;
      char c;
      cin >> x >> c;
      T.update(1, 1, n, x, n, -value(s[x]));
      s[x] = c;
      T.update(1, 1, n, x, n, value(s[x]));
    } else {
      int l, r;
      cin >> l >> r;
      cout << (T.query(1, 1, n, l, r) >= T.query(1, 1, n, l - 1, l - 1) ? "Yes\n" : "No\n");
    }
  }
  return 0;
}