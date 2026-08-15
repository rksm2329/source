#include <bits/stdc++.h>
#define ls(x) node[x].ls
#define rs(x) node[x].rs
#define sz(x) node[x].sz
#define sum(x) node[x].sum
#define mo(x) node[x].mo
#define rev(x) node[x].rev
#define lv(x) node[x].lv
#define rv(x) node[x].rv
#define res(x) node[x].res
#define pri(x) node[x].pri
#define val(x) node[x].val
#define flag(x) node[x].flag

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 5e5 + 10, INF = 1e9;

mt19937 rnd(random_device{}());
int stk[MAXN], top, n, m, a[MAXN];

struct Node {
  int sz, ls, rs, sum, mo, flag, rev, lv, rv, res, val;
  unsigned pri;
};

struct FHQTreap {
  Node node[MAXN];
  int root;

  int create(int x) {
    int now = stk[top--];
    node[now] = {1, 0, 0, x, 0, 0, 0, max(0, x), max(0, x), x, x, rnd()};
    return now;
  }
  void push_up(int x) {
    sz(x) = sz(ls(x)) + sz(rs(x)) + 1;
    sum(x) = sum(ls(x)) + sum(rs(x)) + val(x);
    lv(x) = max({lv(ls(x)), sum(ls(x)) + lv(rs(x)) + val(x), 0});
    rv(x) = max({rv(rs(x)), rv(ls(x)) + sum(rs(x)) + val(x), 0});
    res(x) = val(x) + max(0, rv(ls(x)) + lv(rs(x)));
    if (ls(x)) res(x) = max(res(x), res(ls(x)));
    if (rs(x)) res(x) = max(res(x), res(rs(x)));
  }
  void _rev(int u) {
    if (!u) return;
    swap(ls(u), rs(u)), swap(lv(u), rv(u)), rev(u) ^= 1;
  }
  void _cov(int u, int v) {
    if (!u) return;
    val(u) = mo(u) = v, sum(u) = v * sz(u);
    lv(u) = rv(u) = max(0, sum(u));
    res(u) = max(v, sum(u));
    flag(u) = 1;
    rev(u) = 0; // 修复点：区间赋值后，翻转标记失去意义，直接清空
  }
  void push_down(int u) {
    if (rev(u)) _rev(ls(u)), _rev(rs(u)), rev(u) = 0;
    if (flag(u)) _cov(ls(u), mo(u)), _cov(rs(u), mo(u)), mo(u) = flag(u) = 0;
  }
  int merge(int u, int v) {
    if (!u || !v) return u + v;
    if (pri(u) < pri(v)) {
      push_down(u);
      rs(u) = merge(rs(u), v);
      push_up(u);
      return u;
    } else {
      push_down(v);
      ls(v) = merge(u, ls(v));
      push_up(v);
      return v;
    }
  }
  pii split_size(int u, int s) {
    if (!u) return {0, 0};
    push_down(u);
    int lv = sz(ls(u));
    if (lv >= s) {
      auto [l, r] = split_size(ls(u), s);
      ls(u) = r, push_up(u);
      return {l, u};
    } else {
      auto [l, r] = split_size(rs(u), s - lv - 1);
      rs(u) = l, push_up(u);
      return {u, r};
    }
  }

  int build(int l, int r) {
    if (l == r) return create(a[l]);
    int mid = l + r >> 1;
    int now = merge(build(l, mid), build(mid + 1, r));
    push_up(now);
    return now;
  }
  int build_vec(int l, int r, const vector<int>& v) {
    if (l == r) return create(v[l]);
    int mid = l + r >> 1;
    int now = merge(build_vec(l, mid, v), build_vec(mid + 1, r, v));
    push_up(now);
    return now;
  }
  void init() {
    root = merge(root, build(1, n));
  }
  void insert(const vector<int> &v, int pos) {
    auto [l, r] = split_size(root, pos);
    root = merge(merge(l, build_vec(0, v.size() - 1, v)), r);
  }
  void remove(int u) {
    stk[++top] = u;
    if (ls(u)) remove(ls(u));
    if (rs(u)) remove(rs(u));
  }
  array<int, 3> split(int l, int r) {
    auto [L, T] = split_size(root, l - 1);
    auto [M, R] = split_size(T, r - l + 1);
    return {L, M, R};
  }
  void erase(int pos, int cnt) {
    if (!cnt) return;
    auto [l, m, r] = split(pos, pos + cnt - 1);
    remove(m), root = merge(l, r);
  }
  void modify(int pos, int cnt, int x) {
    if (!cnt) return;
    auto [l, m, r] = split(pos, pos + cnt - 1);
    _cov(m, x), root = merge(merge(l, m), r);
  }
  void reverse(int pos, int cnt) {
    if (!cnt) return;
    auto [L, M, R] = split(pos, pos + cnt - 1);
    _rev(M);
    root = merge(merge(L, M), R);
  }
  int query_sum(int pos, int cnt) {
    if (!cnt) return 0;
    auto [L, M, R] = split(pos, pos + cnt - 1);
    int res = sum(M);
    root = merge(merge(L, M), R);
    return res;
  }
  int query_max() {
    return node[root].res;
  }
} T;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  top = 5e5;
  iota(stk + 1, stk + top + 1, 1);
  for (int i = 1; i <= n; cin >> a[i++]);
  T.init();
  for (string op; m--; ) {
    cin >> op;
    if (op == "INSERT") {
      int pos, tot;
      vector<int> ins;
      cin >> pos >> tot;
      for (int i = 1, k; i <= tot; i++) {
        cin >> k;
        ins.push_back(k);
      }
      T.insert(ins, pos);
    } else if (op == "DELETE") {
      int pos, tot;
      cin >> pos >> tot;
      T.erase(pos, tot);
    } else if (op == "MAKE-SAME") {
      int pos, tot, c;
      cin >> pos >> tot >> c;
      T.modify(pos, tot, c);
    } else if (op == "REVERSE") {
      int pos, tot;
      cin >> pos >> tot;
      T.reverse(pos, tot);
    } else if (op == "GET-SUM") {
      int pos, tot;
      cin >> pos >> tot;
      cout << T.query_sum(pos, tot) << '\n';
    } else {
      cout << T.query_max() << '\n';
    }
  }
  return 0;
}