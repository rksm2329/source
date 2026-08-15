#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 10;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

struct node {
  int x, y, st;
};

char c[MAXN][MAXN];
int n, m, dis[MAXN][MAXN];
bool vis[MAXN][MAXN];
queue<node> Q;

void record(int x, int y, int cnt) {
  if (x < 1 || x > n || y < 1 || y > m || vis[x][y] || c[x][y] == 'T') {
    return ;
  }
  Q.push({x, y, cnt});
  vis[x][y] = 1;
  dis[x][y] = cnt;
}

void bfs(int sx, int sy) {
  for (record(sx, sy, 0); !Q.empty(); ) {
    node now = Q.front();
    Q.pop();
    for (int i = 0; i < 4; i++) {
      record(now.x + dx[i], now.y + dy[i], now.st + 1);
    }
  }
}

int main() {
  memset(dis, 0x3f, sizeof(dis));
  int sx, sy, ax, ay;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> c[i][j];
      if (c[i][j] == 'E') sx = i, sy = j;
      if (c[i][j] == 'S') ax = i, ay = j;
    }
  }
  bfs(sx, sy);
  int ans = 0, num = dis[ax][ay];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (dis[i][j] <= num && isdigit(c[i][j])) ans += c[i][j] - '0';
    }
  }
  cout << ans;
  return 0;
}