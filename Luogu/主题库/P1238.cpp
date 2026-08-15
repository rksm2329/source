#include <iostream>

using namespace std;

const int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};

int n, m, sx, sy, fx, fy, a[20][20], kx[400], ky[400];
bool v[20][20], flag;

void dfs(int x, int y, int tot) {
  if (x < 1 || x > n || y < 1 || y > m || a[x][y] == 0) {
    return;
  }
  if (x == fx && y == fy) {
    flag = 1;
    for (int i = 1; i <= tot; i++) {
      cout << '(' << kx[i] << ',' << ky[i] << ')' << "->";
    }
    cout << '(' << fx << ',' << fy << ')' << '\n';
    return;
  }
  a[x][y] = 0;
  for (int i = 0; i < 4; i++) {
    kx[tot + 1] = x;
    ky[tot + 1] = y;
    dfs(x + dx[i], y + dy[i], tot + 1);
  }
  a[x][y] = 1;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  cin >> sx >> sy >> fx >> fy;
  dfs(sx, sy, 0);
  if (flag == 0) {
    cout << -1;
  }
  return 0;
}