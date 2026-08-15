#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e2 + 10;
const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

struct Node {
  int x, y;
};

int n, m, ans;
char c;
bool a[MAXN][MAXN];
bool vis[MAXN][MAXN];
queue<Node> Q;

void Record(int x, int y) {
  if (x < 1 || x > n || y < 1 || y > m || vis[x][y] || !a[x][y]) {
    return;
  }
  vis[x][y] = 1;
  Q.push({x, y});
}

void bfs(int x, int y) {
  for (Record(x, y); !Q.empty();) {
    Node now = Q.front();
    Q.pop();
    for (int dir = 0; dir < 8; dir++) {
      Record(now.x + dx[dir], now.y + dy[dir]);
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> c;
      a[i][j] = (c == 'W');
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!vis[i][j] && a[i][j]) {
        bfs(i, j);
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}