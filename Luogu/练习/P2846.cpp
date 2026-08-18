#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10;

struct Node {
  ll sum, len;
};

struct Tag {
  ll val;
  bool operator==(const Tag &oth) const {
    return val == oth.val;
  }
};

struct SegTree {
  Node dat[MAXN << 2], E = {0};
  Tag tag[MAXN << 2], I = {0};
  Node comb(const Node &dat1, const Node &dat2) {
    return {dat1.sum + dat2.sum, dat1.len + dat2.len};
  }
  Tag F(const Tag &tag1, const Tag &tag2) {
    return {tag1.val ^ tag2.val};
  }
  Node f(const Node &dat, const Tag &tag) {
    return {tag.val ? dat.len - dat.sum : dat.sum, dat.len};
  }
  void build(int root, int l, int r) {
    tag[root] = I;
    if (l == r) {
      dat[root].len = 1;
      return;
    }
    int mid = l + r >> 1;
    build(root << 1, l, mid);
    build(root << 1 | 1, mid + 1, r);
    dat[root] = comb(dat[root << 1], dat[root << 1 | 1]);
  }
  void down(int root) {
    if (tag[root] == I) return;
    tag[root << 1] = F(tag[root << 1], tag[root]);
    tag[root << 1 | 1] = F(tag[root << 1 | 1], tag[root]);
    dat[root << 1] = f(dat[root << 1], tag[root]);
    dat[root << 1 | 1] = f(dat[root << 1 | 1], tag[root]);
    tag[root] = I;
  }
  void modify(int root, int l, int r, int L, int R, Tag t) {
    if (L <= l && R >= r) {
      tag[root] = F(tag[root], t);
      dat[root] = f(dat[root], t);
      return;
    }
    down(root);
    int mid = l + r >> 1;
    if (L <= mid) modify(root << 1, l, mid, L, R, t);
    if (R > mid) modify(root << 1 | 1, mid + 1, r, L, R, t);
    dat[root] = comb(dat[root << 1], dat[root << 1 | 1]);
  }
  Node query(int root, int l, int r, int L, int R) {
    if (L <= l && R >= r) return dat[root];
    if (L > r || R < l) return E;
    down(root);
    int mid = l + r >> 1;
    return comb(query(root << 1, l, mid, L, R), query(root << 1 | 1, mid + 1, r, L, R));
  }
} T;

int n, m;

void Work(int op, int l, int r) {
  cin >> op >> l >> r;
  if (op == 0) {
    T.modify(1, 1, n, l, r, {1});
  } else {
    cout << T.query(1, 1, n, l, r).sum << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  T.build(1, 1, n);
  for (int op, l, r; m--; Work(op, l, r));
  return 0;
}
