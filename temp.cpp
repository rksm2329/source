#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;

struct SegTree {
  ll sum0[MAXN << 2], sum1[MAXN << 2];
  int cnt[MAXN << 2];
  #define mid (l + r >> 1)
  #define lc root << 1
  #define rc root << 1 | 1
  #define LC lc, l, mid
  #define RC rc, mid + 1, r
  ll get_sum0(int root) {
    if (cnt[root] >= 1) return 0;
    return sum0[root];
  }
  ll get_sum1(int root) {
    if (cnt[root] == 0) return sum1[root];
    if (cnt[root] == 1) return sum0[root];
    return 0;
  }
  void pushup(int root) {
    sum0[root] = get_sum0(lc) + get_sum0(rc);
    sum1[root] = get_sum1(lc) + get_sum1(rc);
  }
  void build(int root, int l, int r) {
    cnt[root] = sum1[root] = 0;
    if (l == r) {
      cin >> sum0[root];
      return;
    }
    build(LC), build(RC);
    pushup(root);
  }
  void update(int root, int l, int r, int L, int R) {
    if (L <= l && R >= r) {
      cnt[root]++;
      return;
    }
    if (L <= mid) update(LC, L, R);
    if (R > mid) update(RC, L, R);
    pushup(root);
  }
} T;

int n;

void Solve() {
  cin >> n;
  T.build(1, 1, n);
  for (int i = 1, l, r; i <= n; i++) {
    cin >> l >> r;
    T.update(1, 1, n, l, r);
    cout << T.get_sum1(1) << ' ';
  }
  cout << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  for (cin >> T; T--; Solve());
  return 0;
}