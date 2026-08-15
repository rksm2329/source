#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e3 + 10;
const long long INF = 2e18;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

struct Node {
  int x, y;
  bool f;
  long long sum;
};

struct cmp {
  bool operator()(const Node &i, const Node &j) {
    return i.sum > j.sum;
  }
};

int n, m, w, a[MAXN][MAXN];
long long dis[MAXN][MAXN];
long long dis2[MAXN][MAXN];
long long dis3[MAXN][MAXN][2];
queue<Node> q;

void R(int x, int y, long long sum) {
  if (x < 1 || x > n || y < 1 || y > m || dis[x][y] != INF || a[x][y] == -1) {
    return;
  }
  dis[x][y] = sum;
  q.push({x, y, 0, sum});
}

void R2(int x, int y, long long sum) {
  if (x < 1 || x > n || y < 1 || y > m || dis2[x][y] != INF || a[x][y] == -1) {
    return;
  }
  dis2[x][y] = sum;
  q.push({x, y, 0, sum});
}

void bfs1() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dis[i][j] = INF;
    }
  }
  R(1, 1, 0);
  while (!q.empty()) {
    Node now = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      R(now.x + dx[i], now.y + dy[i], now.sum + w);
    }
  }
}

void bfs2() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dis2[i][j] = INF;
    }
  }
  R2(n, m, 0);
  while (!q.empty()) {
    Node now = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      R2(now.x + dx[i], now.y + dy[i], now.sum + w);
    }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> w;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  bfs1();
  bfs2();
  long long ans1 = INF;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] > 0) {
        ans1 = min(ans1, dis[i][j] + a[i][j]);
      }
    }
  }
  long long ans2 = INF;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] > 0) {
        ans2 = min(ans2, dis2[i][j] + a[i][j]);
      }
    }
  }
  cout << (min({dis[n][m], ans1 + ans2}) == INF ? -1 : min({dis[n][m], ans1 + ans2}));
  return 0;
}