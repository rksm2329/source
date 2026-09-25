#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10, INF = 1e9;

struct Node {
  int mi, cnt;
  Node operator+(Node i) {
    Node res = {min(mi, i.mi), 0};
    if (mi < i.mi) res.cnt = cnt;
    else if (mi > i.mi) res.cnt = i.cnt;
    else res.cnt = cnt + i.cnt;
    return res;
  }
  Node operator+=(int x) {
    mi += x;
    return *this;
  }
};

struct SegTree {
  Node dat[MAXN << 2], E = {INF, 0};
  int tag[MAXN << 2];
  #define mid (l + r >> 1)
  #define lc root << 1
  #define rc root << 1 | 1
  #define LC lc, l, mid
  #define RC rc, mid + 1, r
  void build(int root, int l, int r) {
    tag[root] = 0;
    if (l == r) {
      dat[root] = {0, 1};
      return;
    }
    build(LC), build(RC);
    dat[root] = dat[lc] + dat[rc];
  }
  void down(int root) {
    if (!tag[root]) return;
    tag[lc] += tag[root], tag[rc] += tag[root];
    dat[lc] += tag[root], dat[rc] += tag[root];
    tag[root] = 0;
  }
  void update(int root, int l, int r, int L, int R, int val) {
    if (L > R) return;
    if (L <= l && R >= r) {
      dat[root] += val, tag[root] += val;
      return;
    }
    down(root);
    if (L <= mid) update(LC, L, R, val);
    if (R > mid) update(RC, L, R, val);
    dat[root] = dat[lc] + dat[rc];
  }
  Node query(int root, int l, int r, int L, int R) {
    if (L <= l && R >= r) return dat[root];
    if (L > r || R < l) return E;
    down(root);
    return query(LC, L, R) + query(RC, L, R);
  }
} T;

int n, a[MAXN], pos[MAXN];
bool vis[MAXN];

void Solve() {
  cin >> n;
  for (int i = 1; i <= n; cin >> a[i++]);
  ll ans = 0;
  for (int l = 1; l <= n; l++) {
    fill(pos + 1, pos + n + 1, 0);
    fill(vis + 1, vis + n + 1, 0);
    T.build(1, 1, n);
    pos[a[l]] = l, vis[a[l]] = 1;
    for (int r = l + 1; r <= n; r++) {
      if (pos[a[r]]) T.update(1, 1, n, pos[a[r]] + vis[a[r]], r - 1, 1);
      vis[a[r]] = !pos[a[r]], pos[a[r]] = r;
      ans += T.query(1, 1, n, l, r).cnt;
    }
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  for (cin >> T; T--; Solve());
  return 0;
}