#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 4e4 + 10, INF = 2e9;

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
    dat[root] = max(dat[lc], dat[rc]);
  }
  int query(int root, int l, int r, int L, int R) {
    if (L <= l && R >= r) return dat[root];
    if (L > r || R < l) return -INF;
    down(root);
    return max(query(LC, L, R), query(RC, L, R));
  }
} T[55];

int n, k, a[MAXN], pos[MAXN];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; cin >> a[i++]);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) T[j].update(1, 0, n, pos[a[i]], i - 1, 1);
    for (int j = k; j >= 1; j--) {
      int now = T[j - 1].query(1, 0, n, 0, i - 1);
      T[j].update(1, 0, n, i, i, now);
    }
    pos[a[i]] = i;
  }
  cout << T[k].query(1, 0, n, n, n);
  return 0;
}