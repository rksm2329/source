// O(4 ^ (n * m))
// 状态：当前格子是否走过，是否超出边界，坐标为(x,y)
// 如合法，那么有 (x + 1,y),(x + 1,y + 1),(x + 1,y - 1),(x - 1,y),(x - 1,y +
// 1),(x - 1,y - 1),(x,y + 1),(x,y - 1)
#include <iostream>

using namespace std;

const int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};

int n, m, t, sx, sy, fx, fy, x, y, ans;

bool v[20][20];

void dfs(int x, int y) {
  if (x < 1 || x > n || y < 1 || y > m || v[x][y]) {
    return;
  }
  if (x == fx && y == fy) {
    ans++;
    return;
  }
  v[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    dfs(x + dx[i], y + dy[i]);
  }
  v[x][y] = 0;
}

int main() {
  cin >> n >> m >> t >> sx >> sy >> fx >> fy;
  for (int i = 1; i <= t; i++) {
    cin >> x >> y;
    v[x][y] = 1;
  }
  dfs(sx, sy);
  cout << ans;
  return 0;
}