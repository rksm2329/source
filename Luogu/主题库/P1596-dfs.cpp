#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e2 + 10, dx[] = {0, 0, 1, -1, -1, -1, 1, 1},
          dy[] = {1, -1, 0, 0, -1, 1, -1, 1};

int n, m, ans, vis[MAXN][MAXN];
char s[MAXN][MAXN];

void dfs(int x, int y) {
  if (x < 1 || x > n || y < 1 || y > m || vis[x][y] || s[x][y] == '.') {
    return;
  }
  vis[x][y] = 1;
  for (int i = 0; i < 8; i++) {
    dfs(x + dx[i], y + dy[i]);
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> s[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == 'W' && !vis[i][j]) {
        ans++;
        dfs(i, j);
      }
    }
  }
  cout << ans;
  return 0;
}