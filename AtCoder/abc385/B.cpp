#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, x, y;
bool vis[110][110];
char a[110][110];
string t;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> x >> y;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  cin >> t;
  int ans = 0;
  for (int i = 0; i < t.size(); i++) {
    int nx = x, ny = y;
    if (t[i] == 'U') {
      nx--;
    } else if (t[i] == 'D') {
      nx++;
    } else if (t[i] == 'L') {
      ny--;
    } else if (t[i] == 'R') {
      ny++;
    }
    if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] != '#') {
      x = nx, y = ny;
      ans += (a[x][y] == '@') * !vis[x][y];
      vis[x][y] = 1;
    }
  }
  cout << x << ' ' << y << ' ' << ans;
  return 0;
}