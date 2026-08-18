#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n, m;
int op, x, y, k;

template <typename T> class SegmentTree {
  vector<T> tree, lazy;
  vector<T> *arr;
  int n, root, n4, end;

  void maintain(int cl, int cr, int p) {
    int cm = cl + (cr - cl) / 2;
    if (cl != cr && lazy[p]) {
      lazy[p * 2] += lazy[p];
      lazy[p * 2 + 1] += lazy[p];
      tree[p * 2] += lazy[p] * (cm - cl + 1);
      tree[p * 2 + 1] += lazy[p] * (cr - cm);
      lazy[p] = 0;
    }
  }

  T range_sum(int l, int r, int cl, int cr, int p) {
    if (l <= cl && cr <= r) {
      return tree[p];
    }
    int m = cl + (cr - cl) / 2;
    T sum = 0;
    maintain(cl, cr, p);
    if (l <= m) {
      sum += range_sum(l, r, cl, m, p * 2);
    }
    if (r > m) {
      sum += range_sum(l, r, m + 1, cr, p * 2 + 1);
    }
    return sum;
  }

  void range_add(int l, int r, T val, int cl, int cr, int p) {
    if (l <= cl && cr <= r) {
      lazy[p] += val;
      tree[p] += (cr - cl + 1) * val;
      return;
    }
    int m = cl + (cr - cl) / 2;
    maintain(cl, cr, p);
    if (l <= m)
      range_add(l, r, val, cl, m, p * 2);
    if (r > m)
      range_add(l, r, val, m + 1, cr, p * 2 + 1);
    tree[p] = tree[p * 2] + tree[p * 2 + 1];
  }

  void range_set(int l, int r, T val, int cl, int cr, int p) {
    if (l <= cl && cr <= r) {
      lazy[p] = val;
      tree[p] = (cr - cl + 1) * val;
      return;
    }
    int m = cl + (cr - cl) / 2;
    maintain(cl, cr, p);
    if (l <= m)
      range_set(l, r, val, cl, m, p * 2);
    if (r > m)
      range_set(l, r, val, m + 1, cr, p * 2 + 1);
    tree[p] = tree[p * 2] + tree[p * 2 + 1];
  }

public:
  void build(int s, int t, int p) {
    if (s == t) {
      tree[p] = (*arr)[s];
      return;
    }
    int m = s + (t - s) / 2;
    build(s, m, p * 2);
    build(m + 1, t, p * 2 + 1);
    tree[p] = tree[p * 2] + tree[p * 2 + 1];
  }

  explicit SegmentTree<T>(vector<T> v) {
    n = v.size();
    n4 = n * 4;
    tree = vector<T>(n4, 0);
    lazy = vector<T>(n4, 0);
    arr = &v;
    end = n - 1;
    root = 1;
    build(0, end, 1);
    arr = nullptr;
  }

  void show(int p, int depth = 0) {
    if (p > n4 || !tree[p]) {
      return;
    }
    show(p * 2, depth + 1);
    for (int i = 0; i < depth; ++i) {
      putchar('\t');
    }
    cout << tree[p] << ":" << lazy[p] << '\n';
    show(p * 2 + 1, depth + 1);
  }

  T range_sum(int l, int r) { return range_sum(l, r, 0, end, root); }

  void range_add(int l, int r, int val) { range_add(l, r, val, 0, end, root); }

  void range_set(int l, int r, int val) { range_set(l, r, val, 0, end, root); }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  vector<long long> tmp = {0};
  cin >> n >> m;
  for (int i = 1, x; i <= n; i++) {
    cin >> x;
    tmp.push_back(x);
  }
  SegmentTree<long long> tree(tmp);
  while (m--) {
    cin >> op >> x >> y;
    if (op == 1) {
      cin >> k;
      tree.range_add(x, y, k);
    } else {
      cout << tree.range_sum(x, y) << '\n';
    }
  }
  return 0;
}