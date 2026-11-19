#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 5e5 + 10;

int n, high[MAXN], down[MAXN], up[MAXN], upd[MAXN], ans, sum;
vector<int> g[MAXN];
array<int, 3> mx[MAXN];

void chkmax(pair<int, int> &res, int k) {
  if (k >= res.first) res.second = res.first, res.first = k;
  else if (k > res.second) res.second = k;
}

void chkmax(array<int, 3> &res, int k) {
  auto &[mx1, mx2, mx3] = res;
  if (k >= mx1) mx3 = mx2, mx2 = mx1, mx1 = k;
  else if (k >= mx2) mx3 = mx2, mx2 = k;
  else if (k > mx3) mx3 = k;
}

void chkmax(array<int, 4> &res, int k) {
  for (int i = 0; i < 4; i++) {
    if (k >= res[i]) {
      for (int j = 3; j > i; j--) res[j] = res[j - 1];
      res[i] = k;
      break;
    }
  }
}

int dfs(int u, int fa) {
  mx[u] = {0, 0, 0}, high[u] = down[u] = 0;
  for (int v : g[u]) {
    if (v == fa) continue;
    dfs(v, u);
    down[u] = max(down[u], down[v]);
    chkmax(mx[u], high[v] + 1);
  }
  auto &[mx1, mx2, mx3] = mx[u];
  down[u] = max(down[u], mx1 + mx2);
  return high[u] = mx1;
}

void solve(int u, int fa) {
  pair<int, int> kmx = {0, 0};
  array<int, 4> val = {0, 0, 0, 0};
  if (fa) chkmax(val, upd[u]);
  for (int v : g[u]) {
    if (v == fa) continue;
    chkmax(kmx, down[v]);
    chkmax(val, high[v] + 1);
  }
  sum = max(sum, val[0] + val[1] + val[2] + val[3]);
  array<int, 3> now = mx[u];
  chkmax(now, upd[u]);
  for (int v : g[u]) {
    if (v == fa) continue;
    auto [mx1, mx2, mx3] = now;
    int kmx1 = mx1, kmx2 = mx2;
    if (mx1 == high[v] + 1) kmx1 = kmx2, kmx2 = mx3;
    else if (mx2 == high[v] + 1) kmx2 = mx3;
    upd[v] = kmx1 + 1;
    up[v] = max({up[u], kmx1 + kmx2, kmx.first == down[v] ? kmx.second : kmx.first});
    ans = max(ans, up[v] + down[v] + 1);
    solve(v, u);
  }
}

void Solve() {
  cin >> n;
  for (int i = 1; i <= n; g[i++].clear());
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  up[1] = upd[1] = ans = sum = 0;
  solve(1, 0);
  cout << min(2 * (n - 1) - ans, 2 * n - sum - 1) << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  for (cin >> T; T--; Solve());
  return 0;
}