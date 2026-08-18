#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e2 + 10, INF = 3e4;
const int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};

int n, m, x, y, c, ans = INF, a[MAXN][MAXN], dp[MAXN][MAXN][2][3];
bool vis[MAXN][MAXN];

void dfs(int x, int y, int f, int c, int g) {
  if (x < 1 || x > m || y < 1 || y > m || vis[x][y] || g >= ans ||
      g >= dp[x][y][f][c]) {
    return;
  }
  dp[x][y][f][c] = g;
  if (x == m && y == m) {
    ans = min(ans, g);
    return;
  }
  vis[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (a[nx][ny]) {
      dfs(nx, ny, 0, a[nx][ny], g + (a[nx][ny] != c));
    } else if (!f) {
      dfs(nx, ny, 1, a[x][y], g + 2);
    }
  }
  vis[x][y] = 0;
}

int main() {
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y >> c;
    a[x][y] = ++c;
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      for (int f = 0; f < 2; f++) {
        for (int c = 1; c <= 2; c++) {
          dp[i][j][f][c] = INF;
        }
      }
    }
  }
  dfs(1, 1, 0, a[1][1], 0);
  cout << (ans == INF ? -1 : ans);
  return 0;
}