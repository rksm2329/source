#include <bits/stdc++.h>
#define fa(x) node[x].fa
#define val(x) node[x].val
#define cnt(x) node[x].cnt
#define sz(x) node[x].sz
#define ch(x, id) node[x].ch[id]
#define rev(x) node[x].rev

using namespace std;
using ll = long long;

const int MAXN = 2e6 + 10;

struct Node {
  int fa, val, cnt, sz, ch[2], rev;
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
  void _rev(int u) {
    if (!u) return;
    swap(ch(u, 0), ch(u, 1)), rev(u) ^= 1;
  }
  void push_down(int x) {
    if (rev(x)) {
      if (ch(x, 0)) _rev(ch(x, 0));
      if (ch(x, 1)) _rev(ch(x, 1));
      rev(x) = 0;
    }
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
  void loc(int &rt, int k) {
    int u = rt;
    while (u) {
      push_down(u);
      if (sz(ch(u, 0)) >= k) {
        u = ch(u, 0);
      } else if (sz(ch(u, 0)) + 1 == k) {
        break;
      } else {
        k -= sz(ch(u, 0)) + 1;
        u = ch(u, 1);
      }
    }
    splay(rt, u);
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
  void reverse(int l, int r) {
    loc(root, l); 
    loc(ch(root, 1), r - l + 2);
    int u = ch(ch(root, 1), 0);
    _rev(u);
  }
  void print(int u) {
    if (!u) return;
    push_down(u);
    print(ch(u, 0));
    if (val(u) >= 1 && val(u) <= MAXN) {
      cout << val(u) << ' ';
    }
    print(ch(u, 1));
  }
  void print() {
    loc(root, 1);
    loc(ch(root, 1), sz(root) - 1);
    print(ch(ch(root, 1), 0));
  }
} T;

int n, m;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i <= n + 1; T.insert(i++));
  for (int l, r; m--; ) {
    cin >> l >> r;
    T.reverse(l, r);
  }
  T.print();
  return 0;
}