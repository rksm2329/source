#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e2 + 10, INF = 3e4;
const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

struct node {
  int x, y, f, c, g;
} que[MAXN * MAXN];

int a[MAXN][MAXN], dp[MAXN][MAXN][2][3];
int n, m, x, y, c, ans = INF, head = 1, tail;

bool check(int x, int y) {
  return (x >= 1 && x <= m && y >= 1 && y <= m);
}

void r(int x, int y, int f, int c, int g) {
  if (x < 1 || x > m || y < 1 || y > m || g >= ans || g >= dp[x][y][f][c]) {
    return;
  }
  if (x == m && y == m) {
    ans = min(ans, g);
    return;
  }
  dp[x][y][f][c] = g;
  que[++tail] = {x, y, f, c, g};
}

void bfs() {
  for (r(1, 1, 0, a[1][1], 0); head <= tail; ) {
    node now = que[head++];
    for (int i = 0; i < 4; i++) {
      int nx = now.x + dx[i], ny = now.y + dy[i];
      if (!check(nx, ny)) {
        continue ;
      }
      if (a[nx][ny]) {
        r(nx, ny, 0, a[nx][ny], now.g + (a[nx][ny] != now.c));
      } else if (!now.f) {
        r(nx, ny, 1, a[now.x][now.y], now.g + 2);
      }
    }
  }
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
  bfs();
  cout << (ans == INF ? -1 : ans);
  return 0;
}