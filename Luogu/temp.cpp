#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 10, MOD = 998244353, MAXV = 1e3 + 10;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

ll n, m, k, r, ans[MAXN][MAXN][MAXV];
char a[MAXN][MAXN];
bool vis[MAXN][MAXN][MAXV];
queue<array<int, 3>> q;

bool check(int x, int y) {
  return x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] == '.';
}

void R(int x, int y, int d, ll k) {
  (ans[x][y][d] += k) %= MOD;
  if (vis[x][y][d]) return;
  q.push({x, y, d});
  vis[x][y][d] = 1;
}

void bfs(int u, int v) {
  memset(ans, 0, sizeof ans);
  memset(vis, 0, sizeof vis);
  for (; !q.empty(); q.pop());
  q.push({u, v, 0});
  ans[u][v][0] = 1;
  while (!q.empty()) {
    auto &[x, y, d] = q.front(); q.pop();
    if (d == k) continue;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (!check(nx, ny)) nx = x, ny = y;
      R(nx, ny, d + 1, ans[x][y][d]);
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; cin >> a[i][j++]);
  }
  cin >> r;
  for (int i = 1, x, y; i <= r; i++) {
    cin >> x >> y;
    bfs(x, y);
    cout << ans[x][y][k] << '\n';
  }
  return 0;
}