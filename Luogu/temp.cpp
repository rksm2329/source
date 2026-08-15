#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 5e5 + 10;
const ll MOD[2] = {998244353, 19260817};

int n, m, q;
ll h[2][MAXN], a[2][MAXN], b[2][MAXN], c[2][MAXN], sum[2], res[2];
vector<int> g[MAXN];
bool vis[MAXN];

void Work() {
  int op;
  cin >> op;
  if (op == 1) {
    int u, v;
    cin >> u >> v;
    for (int _ : {0, 1}) {
      sum[_] = (sum[_] - h[_][u] + MOD[_]) % MOD[_];
      b[_][v] = (b[_][v] - h[_][u] + MOD[_]) % MOD[_];
      (c[_][v] += h[_][u]) %= MOD[_];
    }
  } else if (op == 3) {
    int u, v;
    cin >> u >> v;
    for (int _ : {0, 1}) {
      (sum[_] += h[_][u]) %= MOD[_];
      (b[_][v] += h[_][u]) %= MOD[_];
      c[_][v] = (c[_][v] - h[_][u] + MOD[_]) % MOD[_];
    }
  } else if (op == 2) {
    int u;
    cin >> u;
    for (int _ : {0, 1}) {
      sum[_] = (sum[_] - b[_][u] + MOD[_]) % MOD[_];
      b[_][u] = 0, c[_][u] = a[_][u];
    }
  } else {
    int u;
    cin >> u;
    for (int _ : {0, 1}) {
      (sum[_] += c[_][u]) %= MOD[_];
      c[_][u] = 0, b[_][u] = a[_][u];
    }
  }
  cout << (sum[0] == res[0] && sum[1] == res[1] ? "YES\n" : "NO\n");
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  mt19937_64 rnd(random_device{}());
  for (int i = 1; i <= n; i++) {
    for (int _ : {0, 1}) {
      h[_][i] = rnd() % MOD[_];
      (res[_] += h[_][i]) %= MOD[_];
    }
  }
  for (int i = 1, u, v; i <= m; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    for (int _ : {0, 1}) {
      (sum[_] += h[_][u]) %= MOD[_];
      (a[_][v] += h[_][u]) %= MOD[_];
    }
  }
  for (int u = 1; u <= n; u++) {
    for (int _ : {0, 1}) b[_][u] = a[_][u];
  }
  for (cin >> q; q--; Work());
  return 0;
}
