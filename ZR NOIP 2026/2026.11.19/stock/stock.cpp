#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 1e6 + 10;

int n, p, q, a[MAXN];

struct ST {
  int fmin[20][MAXN], fmax[20][MAXN];
  void init(int n, int *a) {
    for (int i = 1; i <= n; i++) fmin[0][i] = fmax[0][i] = a[i];
    for (int k = 1; k <= __lg(n); k++) {
      for (int i = 1; i + (1 << k - 1) <= n; i++) {
        fmin[k][i] = min(fmin[k - 1][i], fmin[k - 1][i + (1 << k - 1)]);
        fmax[k][i] = max(fmax[k - 1][i], fmax[k - 1][i + (1 << k - 1)]);
      }
    }
  }
  int qmin(int l, int r) {
    int k = __lg(r - l + 1);
    return min(fmin[k][l], fmin[k][r - (1 << k) + 1]);
  }
  int qmax(int l, int r) {
    int k = __lg(r - l + 1);
    return max(fmax[k][l], fmax[k][r - (1 << k) + 1]);
  }
} S;

class SegTree {
private:
  struct Node {
    int mx, mi;
    Node operator+=(const int oth) {
      mx += oth, mi += oth;
      return *this;
    }
    Node operator+(const Node &oth) {
      return {max(mx, oth.mx), min(mi, oth.mi)};
    }
  } dat[MAXN << 2];
  int tag[MAXN << 2];
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
  bool check(int l1, int r1, int l2, int r2) {
    int L = max(l1, l2), R = min(r1, r2);
    return L <= R;
  }

public:
  void update(int root, int l, int r, int L, int R, int val) {
    if (L <= l && R >= r) {
      dat[root].mi += val, dat[root].mx += val, tag[root] += val;
      return;
    }
    down(root);
    if (L <= mid) update(LC, L, R, val);
    if (R > mid) update(RC, L, R, val);
    dat[root] = dat[lc] + dat[rc];
  }
  int query(int root, int l, int r, int L, int R) {
    if (l == r) return dat[root].mi >= -q && dat[root].mi <= q ? l : n + 1;
    down(root);
    if (L <= l && R >= r) {
      if (check(dat[lc].mi, dat[lc].mx, -q, q)) {
        int res = query(LC, L, R);
        if (res != n + 1) return res;
      }
      if (check(dat[rc].mi, dat[rc].mx, -q, q)) {
        int res = query(RC, L, R);
        if (res != n + 1) return res;
      }
      return n + 1;
    }
    int ans = n + 1;
    if (L <= mid) ans = min(ans, query(LC, L, R));
    if (R > mid) ans = min(ans, query(RC, L, R));
    return ans;
  }
  Node query(int root, int l, int r, int pos) {
    if (l == r) return dat[root];
    down(root);
    return pos <= mid ? query(LC, pos) : query(RC, pos);
  }
  #undef mid
} T;

int main() {
  freopen("stock.in", "r", stdin);
  freopen("stock.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> p >> q;
  for (int i = 1; i <= n; cin >> a[i++]);
  S.init(n, a);
  int ans = 1, L = 1;
  for (int r = 2, l = 1; r <= n; r++) {
    for (; l <= r && S.qmax(l, r) - S.qmin(l, r) > p; l++);
    if (a[r] > a[r - 1]) T.update(1, 1, n, 1, r - 1, 1);
    else if (a[r] < a[r - 1]) T.update(1, 1, n, 1, r - 1, -1);
    int kl = T.query(1, 1, n, l, r - 1);
    if (r - kl + 1 > ans) ans = r - kl + 1, L = kl;
  }
  cout << ans << ' ' << L;
  return 0;
}