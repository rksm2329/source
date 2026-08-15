#include <bits/stdc++.h>
#define fa(x) node[x].fa
#define val(x) node[x].val
#define cnt(x) node[x].cnt
#define sz(x) node[x].sz
#define ch(x, id) node[x].ch[id]
#define add(x) node[x].add

using namespace std;
using ll = long long;

const int MAXN = 2e6 + 10;

int run;

struct Node {
  int fa, val, cnt, sz, ch[2], add;
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
    while (u) {
      if (sz(ch(u, 0)) >= k) {
        u = ch(u, 0);
      } else if (sz(ch(u, 0)) + cnt(u) >= k) {
        break;
      } else {
        k -= sz(ch(u, 0)) + cnt(u);
        u = ch(u, 1);
      }
    }
    splay(rt, u);
  }
  
  int rnk(int val) {
    find_key(root, val);
    return sz(ch(root, 0)) + (val(root) < val ? cnt(root) : 0) + 1;
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
  void update(int x) {
    add(root) += x;
  }
  void check(int x) {
    int rk = rnk(x);
    if (rk == sz(root) + 1) {
      run += sz(root);
      loc(root, rk);
      push_up(root);
      return;
    }
    loc(root, rk);
    run += sz(ch(root, 0));
    ch(root, 0) = 0;
    push_up(root);
  }
  int kth(int k) {
    if (k > sz(root)) return -1;
    loc(root, k);
    return val(root);
  }
} T;

int n, mi, delta;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> mi;
  for (char op; n--; ) {
    int k;
    cin >> op >> k;
    if (op == 'I') {
      if (k < mi) continue;
      T.insert(k - delta);
    } else if (op == 'A') {
      delta += k;
    } else if (op == 'S') {
      delta -= k, T.check(mi - delta);
    } else {
      if (k > T.sz(T.root)) {
        cout << "-1\n";
        continue;
      }
      int ans = T.kth(T.sz(T.root) - k + 1);
      cout << ans + delta << '\n';
    }
  }
  cout << run;
  return 0;
}