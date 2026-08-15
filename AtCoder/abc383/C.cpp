#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 10;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

struct Node {
  int x, y, step;
};

int n, m, d, dis[MAXN][MAXN];
char a[MAXN][MAXN];
vector<pair<int, int>> v;
queue<Node> q;

void R(int x, int y, int step) {
  if (x < 1 || x > n || y < 1 || y > m || step > d || a[x][y] == '#' || dis[x][y] != -1) {
    return;
  }
  dis[x][y] = step;
  q.push({x, y, step});
}

void bfs() {
  while (!q.empty()) {
    Node now = q.front();
    int x = now.x, y = now.y, step = now.step;
    q.pop();
    for (int i = 0; i < 4; i++) {
      R(x + dx[i], y + dy[i], step + 1);
    }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> d;
  memset(dis, -1, sizeof(dis));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'H') {
        R(i, j, 0);
      }
    }
  }
  bfs();
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (dis[i][j] != -1) {
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}