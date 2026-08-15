#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e2 + 10;

int n, cnt[MAXN];
bool a[MAXN][MAXN], col[MAXN];
vector<int> g[MAXN];

void dfs(int u, int fa, int c) {
  col[u] = c, cnt[c]++;
  for (int v : g[u]) {
    if (v != fa) {
      dfs(v, u, c ^ 1);
    }
  }
}

void Solve() {
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (col[i] != col[j] && !a[i][j]) {
        a[i][j] = a[j][i] = 1;
        cout << i << ' ' << j << endl;
        return;
      }
    }
  }
}

void Work() {
  int u, v;
  cin >> u >> v;
  if (u == -1) {
    exit(0);
  }
  a[u][v] = a[v][u] = 1;
}

int main() {
  cin >> n;
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    a[u][v] = a[v][u] = 1;
  }
  dfs(1, 0, 0);
  cout << ((cnt[0] * cnt[1] - n + 1) & 1 ? "First" : "Second") << endl;
  int k = (cnt[0] * cnt[1] - n + 1) & 1;
  while (1) {
    if (k) {
      Solve();
    } else {
      Work();
    }
    k ^= 1;
  }
  return 0;
}