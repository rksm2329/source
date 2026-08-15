#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 3e5 + 10;

struct Fenwick {
  ll n, dat[MAXN];
  void init(int n) {
    this->n = n;
    fill(dat + 1, dat + n + 1, 0);
  }
  ll query(int x) {
    ll res = 0;
    for (; x; res += dat[x], x -= x & -x);
    return res;
  }
  void modify(int x, int val) {
    for (; x <= n; dat[x] += val, x += x & -x);
  }
} T;

int n, q, f[MAXN], dfn[MAXN], mx[MAXN], ts;
pair<int, int> e[MAXN];
vector<int> g[MAXN];

void dfs(int u, int fa) {
  f[u] = fa, dfn[u] = mx[u] = ++ts;
  for (int v : g[u]) {
    if (v == fa) continue;
    dfs(v, u);
    mx[u] = max(mx[u], mx[v]);
  }
}

void Work(int op, int x, int y) {
  cin >> op >> x;
  if (op == 1) {
    cin >> y;
    T.modify(dfn[x], y);
  } else {
    ll r1 = T.query(mx[e[x].first]) - T.query(dfn[e[x].first - 1]);
    ll r2 = T.query(n) - r1;
    cout << abs(r1 - r2) << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> e[i].first >> e[i].second;
    g[e[i].first].push_back(e[i].second);
    g[e[i].second].push_back(e[i].first);
  }
  dfs(1, 0);
  for (int i = 1; i < n; i++) {
    if (f[e[i].second] == e[i].first) swap(e[i].first, e[i].second);
  }
  T.init(n);
  for (int i = 1; i <= n; T.modify(i++, 1));
  cin >> q;
  for (int op, x, y; q--; Work(op, x, y));
  return 0;
}