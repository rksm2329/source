#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10;

int n, q, m;

struct Node {
  ll sum, len, mid;
};

struct Tag {
  ll mul, add;
};

struct SegTree {
  Node dat[MAXN << 2];
  Tag tag[MAXN << 2];
  Node E = {0};
  Tag I = {1, 0};
  Node comb(const Node &dat1, const Node &dat2) {
    return {(dat1.sum + dat2.sum) % m, dat1.len + dat2.len};
  }
  Tag F(const Tag &tag1, const Tag &tag2) {
    return {tag1.mul * tag2.mul % m, (tag1.add * tag2.mul % m + tag2.add) % m};
  }
  Node f(const Node &dat, const Tag &tag) {
    return {(dat.sum * tag.mul % m + dat.len * tag.add % m) % m, dat.len, dat.mid};
  }
  void build(int root, int l, int r) {
    tag[root] = I;
    if (l == r) {
      cin >> dat[root].sum;
      dat[root].len = 1;
      return;
    }
    int mid = l + r >> 1;
    build(root << 1, l, mid);
    build(root << 1 | 1, mid + 1, r);
    dat[root] = comb(dat[root << 1], dat[root << 1 | 1]);
    dat[root].mid = mid;
  }
  void down(int root) {
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
    if (L <= dat[root].mid) {
      modify(root << 1, l, dat[root].mid, L, R, t);
    }
    if (R > dat[root].mid) {
      modify(root << 1 | 1, dat[root].mid + 1, r, L, R, t);
    }
    dat[root] = comb(dat[root << 1], dat[root << 1 | 1]);
    dat[root].mid = l + r >> 1;
  }
  Node query(int root, int l, int r, int L, int R) {
    if (L <= l && R >= r) {
      return dat[root];
    }
    if (L > r || R < l) {
      return E;
    }
    down(root);
    return comb(query(root << 1, l, dat[root].mid, L, R), query(root << 1 | 1, dat[root].mid + 1, r, L, R));
  }
} T;

void Work(int op, int l, int r, ll k) {
  cin >> op >> l >> r;
  if (op == 1) {
    cin >> k;
    T.modify(1, 1, n, l, r, {k, 0});
  } else if (op == 2) {
    cin >> k;
    T.modify(1, 1, n, l, r, {1, k});
  } else {
    cout << T.query(1, 1, n, l, r).sum << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  T.build(1, 1, n);
  cin >> q;
  for (ll op, l, r, k; q--; Work(op, l, r, k));
  return 0;
}