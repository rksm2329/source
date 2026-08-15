#include <bits/stdc++.h>

using namespace std;

const int MAXN = 55;

int n, m, fx, fy;
string s;
bool a[MAXN][MAXN];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> fx >> fy;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      a[i][j] = (c == '#');
    }
  }
  cin >> s;
  int x = fx, y = fy;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'L' && y > 1 && !a[x][y - 1]) {
      y--;
    } else if (s[i] == 'R' && y < m && !a[x][y + 1]) {
      y++;
    } else if (s[i] == 'U' && x > 1 && !a[x - 1][y]) {
      x--;
    } else if (s[i] == 'D' && x < n && !a[x + 1][y]) {
      x++;
    }
  }
  cout << x << ' ' << y;
  return 0;
}