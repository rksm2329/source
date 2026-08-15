#include <bits/stdc++.h>

using namespace std;

int n, m1, m2, a[10][10], p[10];
bool g[10][10][3];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m1;
  for (int i = 1, u, v; i <= m1; i++) {
    cin >> u >> v;
    g[u][v][0] = g[v][u][0] = 1;
  }
  cin >> m2;
  for (int i = 1, u, v; i <= m2; i++) {
    cin >> u >> v;
    g[u][v][1] = g[v][u][1] = 1;
    g[u][v][2] = g[v][u][2] = 1;
  }
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  int ans = 2e9;
  for (int i = 1; i <= n; i++) {
    p[i] = i;
  }
  do {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        g[i][j][1] = g[i][j][2];
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i != j && g[i][j][0] != g[p[i]][p[j]][1]) {
          sum += max(a[p[i]][p[j]], a[p[j]][p[i]]);
          g[p[i]][p[j]][1] = g[i][j][0];
          g[p[j]][p[i]][1] = g[j][i][0];
        }
      }
    }
    ans = min(ans, sum);
  } while (next_permutation(p + 1, p + n + 1));
  cout << ans;
  return 0;
}