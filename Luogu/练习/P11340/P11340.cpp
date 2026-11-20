#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 5e5 + 10;

struct SegTree {
  int dat[MAXN << 2], tag[MAXN << 2];
  #define mid (l + r >> 1)
  #define lc root << 1
  #define rc root << 1 | 1
  #define LC lc, l, mid
  #define RC rc, mid + 1, r
  void down(int root) {
    if (!tag[root]) return;
    dat[lc] += tag[root], tag[lc] += tag[root];
    dat[rc] += tag[root], tag[rc] += tag[root];
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
  int query(int root, int l, int r) {
    if (l == r) return l;
    down(root);
    return !dat[lc] ? query(LC) : query(RC);
  }
} T;

int n, m, q, pos[15][MAXN], a[MAXN], b[MAXN];

int calc(int i) {
  int mx = 0;
  for (int k = 2; k <= m; k++) mx = max(mx, pos[k][a[i]]);
  return mx;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> q;
  m = 3;
  for (int i = 1; i <= m; i++) {
    for (int j = 1, x; j <= n; j++) {
      cin >> x;
      pos[i][x] = j;
      if (i == 1) a[j] = x;
    }
  }
  for (int i = 1; i <= n; i++) {
    if ((b[i] = calc(i)) > i) T.update(1, 1, n, i, b[i] - 1, 1);
  }
  for (int i = 1, op; i <= q; i++) {
    cin >> op;
    if (op == 1) {
      int x;
      cin >> x;
      cout << (T.query(1, 1, n) >= pos[1][x] ? "DA\n" : "NE\n");
    } else {
      int x, y, w;
      cin >> w >> x >> y;
      if (w == 1) {
        int p = pos[1][x], q = pos[1][y];
        swap(a[p], a[q]), swap(pos[1][x], pos[1][y]);
        if (b[p] > p) T.update(1, 1, n, p, b[p] - 1, -1);
        if (b[q] > q) T.update(1, 1, n, q, b[q] - 1, -1);
        swap(b[p], b[q]);
        if (b[p] > p) T.update(1, 1, n, p, b[p] - 1, 1);
        if (b[q] > q) T.update(1, 1, n, q, b[q] - 1, 1);
      } else {
        swap(pos[w][x], pos[w][y]);
        int p = pos[1][x], q = pos[1][y];
        if (b[p] > p) T.update(1, 1, n, p, b[p] - 1, -1);
        if (b[q] > q) T.update(1, 1, n, q, b[q] - 1, -1);
        b[p] = calc(p), b[q] = calc(q);
        if (b[p] > p) T.update(1, 1, n, p, b[p] - 1, 1);
        if (b[q] > q) T.update(1, 1, n, q, b[q] - 1, 1);
      }
    }
  }
  return 0;
}