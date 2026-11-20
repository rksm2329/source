#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10;

struct SegTree {
  ll dat[MAXN << 2], tag[MAXN << 2];
  #define mid (l + r >> 1)
  #define LC root << 1, l, mid
  #define RC root << 1 | 1, mid + 1, r
  void build(int root, int l, int r) {
    tag[root] = 0;
    if (l == r) {
      dat[root] = 0;
      return;
    }
    build(LC), build(RC);
    dat[root] = max(dat[root << 1], dat[root << 1 | 1]);
  }
  void down(int root) {
    if (!tag[root]) return;
    dat[root << 1] += tag[root];
    dat[root << 1 | 1] += tag[root];
    tag[root << 1] += tag[root];
    tag[root << 1 | 1] += tag[root];
    tag[root] = 0;
  }
  void update(int root, int l, int r, int L, int R, ll val) {
    if (L > R) return;
    if (L <= l && R >= r) {
      dat[root] += val;
      tag[root] += val;
      return;
    }
    down(root);
    if (L <= mid) update(LC, L, R, val);
    if (R > mid) update(RC, L, R, val);
    dat[root] = max(dat[root << 1], dat[root << 1 | 1]);
  }
  ll query(int root, int l, int r, int L, int R) {
    if (L <= l && R >= r) return dat[root];
    if (L > r || R < l) return 0;
    down(root);
    return max(query(LC, L, R), query(RC, L, R));
  }
} T;

int n, a[MAXN];
ll dp[MAXN];

void Solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  T.build(1, 1, n);
  for (int i = n; i; i--) {
    dp[i] = a[i];
    int l = i + 1, r = min(n, i + a[i]);
    dp[i] = max(dp[i], T.query(1, 1, n, l, r));
    T.update(1, 1, n, l, n, a[i]);
    T.update(1, 1, n, i, i, dp[i]);
  }
  cout << dp[1] << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  for (cin >> T; T--; Solve());
  return 0;
}