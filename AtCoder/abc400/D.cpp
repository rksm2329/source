#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e3 + 10, INF = 1e9;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

struct Node {
  int x, y;
};

int n, m, sx, sy, ex, ey, dis[MAXN][MAXN];
char a[MAXN][MAXN];
deque<Node> q;

void R(int x, int y, int cnt, bool f) {
  if (dis[x][y] <= cnt) {
    return;
  }
  dis[x][y] = cnt;
  if (!f) {
    q.push_front({x, y});
  } else {
    q.push_back({x, y});
  }
}

void bfs() {
  fill(&dis[0][0], &dis[n + 1][m + 1], INF);
  for (R(sx, sy, 0, 0); !q.empty(); ) {
    Node now = q.front();
    q.pop_front();
    for (int i = 0; i < 4; i++) {
      for (int t = 1; t <= 2; t++) {
        int nx = now.x + dx[i] * t, ny = now.y + dy[i] * t;
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
          if (t == 1 && a[nx][ny] == '.') {
            R(nx, ny, dis[now.x][now.y], 0);
          } else if (a[nx][ny] == '#') {
            R(nx, ny, dis[now.x][now.y] + 1, 1);
          }
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  cin >> sx >> sy >> ex >> ey;
  bfs();
  cout << dis[ex][ey];
  return 0;
}