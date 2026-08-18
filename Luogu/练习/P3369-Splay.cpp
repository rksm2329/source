#include <bits/stdc++.h>
#define fa(x) node[x].fa
#define val(x) node[x].val
#define cnt(x) node[x].cnt
#define sz(x) node[x].sz
#define ch(x, id) node[x].ch[id]

using namespace std;
using ll = long long;

const int MAXN = 2e6 + 10;

struct Node {
  int fa, val, cnt, sz, ch[2];
};

struct Splay {
  Node node[MAXN];
  int root, tot;
  bool dir(int x) {
    return x == ch(fa(x), 1);
  }
  void push_up(int x) {
    sz(x) = cnt(x) + sz(ch(x, 0)) + sz(ch(x, 1));
  }
  void rotate(int u) {
    int v = fa(u), w = fa(v);
    bool r = dir(u);
    ch(v, r) = ch(u, r ^ 1);
    ch(u, r ^ 1) = v;
    if (w) ch(w, dir(v)) = u;
    if (ch(v, r)) fa(ch(v, r)) = v;
    fa(v) = u, fa(u) = w;
    push_up(v), push_up(u);
  }
  void splay(int &rt, int u) {
    int w = fa(rt);
    for (int v; (v = fa(u)) != w; rotate(u)) {
      if (fa(v) != w) rotate(dir(u) == dir(v) ? v : u);
    }
    rt = u;
  }
  void find_key(int &rt, int val) {
    int u = rt, v = fa(u);
    for (; u && val(u) != val; u = ch(v = u, val > val(u)));
    splay(rt, u ? u : v);
  }
  void loc(int &rt, int k) {
    int u = rt;
    while (1) {
      if (sz(ch(u, 0)) >= k) u = ch(u, 0);
      else if (sz(ch(u, 0)) + cnt(u) >= k) break;
      else {
        k -= sz(ch(u, 0)) + cnt(u), u = ch(u, 1);
      }
    }
    splay(rt, u);
  }
  int merge(int u, int v) {
    if (!u || !v) return u + v;
    loc(v, 1), ch(v, 0) = u;
    fa(u) = v, push_up(v);
    return v;
  }
  void insert(int val) {
    int u = root, v = 0;
    for (; u && val(u) != val; u = ch(v = u, val > val(u)));
    if (u) cnt(u)++;
    else {
      u = ++tot, val(u) = val, cnt(u) = sz(u) = 1, fa(u) = v;
      if (v) ch(v, val > val(v)) = u;
    }
    splay(root, u);
  }
  bool remove(int val) {
    find_key(root, val);
    if (!root || val(root) != val) return 0;
    cnt(root)--, sz(root)--;
    if (!cnt(root)) {
      int u = ch(root, 0), v = ch(root, 1);
      fa(u) = fa(v) = 0, root = merge(u, v);
    }
    return 1;
  }
  
  int rnk(int val) {
    find_key(root, val);
    return sz(ch(root, 0)) + (val(root) < val ? cnt(root) : 0) + 1;
  }
  int kth(int k) {
    if (k > sz(root)) return -1;
    loc(root, k);
    return val(root);
  }
  int _prev(int val) {
    find_key(root, val);
    if (root && val(root) < val) return val(root);
    int u = ch(root, 0);
    if (!u) return -1;
    for (; ch(u, 1); u = ch(u, 1));
    splay(root, u);
    return val(root);
  }
  int _next(int val) {
    find_key(root, val);
    if (root && val(root) > val) return val(root);
    int u = ch(root, 1);
    if (!u) return -1;
    for (; ch(u, 0); u = ch(u, 0));
    splay(root, u);
    return val(root);
  }
} T;

int n;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int op, x; n--; ) {
    cin >> op >> x;
    if (op == 1) T.insert(x);
    if (op == 2) T.remove(x);
    if (op == 3) cout << T.rnk(x) << '\n';
    if (op == 4) cout << T.kth(x) << '\n';
    if (op == 5) cout << T._prev(x) << '\n';
    if (op == 6) cout << T._next(x) << '\n';
  }
  return 0;
}