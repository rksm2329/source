#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e2 + 10;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

int n, m, sx, sy, fx, fy;
bool vis[MAXN][MAXN];
char s[MAXN][MAXN];

bool check(int x, int y) {
  return x >= 1 && x <= n && y >= 1 && y <= m;
}

void dfs(int x, int y) {
  if (!check(x,y) || vis[x][y] || s[x][y] == '#') {
    return;
  }
  vis[x][y] = 1;
  if (x == fx && y == fy) {
    cout << "Yes";
    exit(0);
  }
  for (int i = 0; i < 4; i++) {
    dfs(x + dx[i], y + dy[i]);
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> s[i][j];
      if (s[i][j] == 's') {
        sx = i, sy = j;
      }
      if (s[i][j] == 'g') {
        fx = i, fy = j;
      }
    }
  }
  dfs(sx, sy);
  cout << "No";
  return 0;
}