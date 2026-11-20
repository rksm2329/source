#include <bits/extc++.h>
#define gp __gnu_pbds::gp_hash_table<string, int>
#define fa(x) node[x].fa
#define val(x) node[x].val
#define cnt(x) node[x].cnt
#define sz(x) node[x].sz
#define ch(x, id) node[x].ch[id]
#define name(x) node[x].name
#define id(x) node[x].id

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 3e5 + 10;

struct Node {
  int fa, cnt, sz, id, ch[2];
  ll val;
  string name;
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

  int insert(ll val, string name, int id) {
    int u = root, p = 0;
    while (u) {
      p = u;
      bool k = val < val(u) || (val == val(u) && id > id(u));
      u = ch(u, k);
    }
    u = ++tot;
    if (p) {
      bool k = val < val(p) || (val == val(p) && id > id(p));
      ch(p, k) = u;
    }
    fa(u) = p, val(u) = val, id(u) = id, name(u) = name, cnt(u) = 1, sz(u) = 1;
    splay(root, u);
    return u;
  }
  void erase(int u) {
    splay(root, u);
    if (!ch(u, 0) || !ch(u, 1)) {
      root = ch(u, 0) + ch(u, 1);
      if (root) fa(root) = 0;
    } else {
      int cur = ch(u, 0);
      for (; ch(cur, 1); cur = ch(cur, 1));
      splay(ch(root, 0), cur);
      ch(cur, 1) = ch(u, 1);
      if (ch(cur, 1)) fa(ch(cur, 1)) = cur;
      fa(cur) = 0, root = cur;
      push_up(root);
    }
  }
  int kth(int k) {
    int u = root;
    while (u) {
      int lv = sz(ch(u, 0));
      if (k <= lv) u = ch(u, 0);
      else if (k == lv + 1) {
        splay(root, u);
        return u;
      } else {
        k -= lv + 1, u = ch(u, 1);
      }
    }
    return 0;
  }
} T;

int n;
gp id;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    if (s[0] == '+') {
      s = s.substr(1);
      ll val;
      cin >> val;
      if (id[s]) T.erase(id[s]);
      id[s] = T.insert(val, s, i);
    } else {
      s = s.substr(1);
      if (isdigit(s[0])) {
        int k = atoi(s.c_str());
        for (int j = k; j <= min(k + 9, T.sz(T.root)); j++) {
          cout << T.name(T.kth(j)) << ' ';
        }
        cout << '\n';
      } else {
        int now = id[s];
        T.splay(T.root, now);
        cout << T.sz(T.ch(now, 0)) + 1 << '\n';
      }
    }
  }
  return 0;
}