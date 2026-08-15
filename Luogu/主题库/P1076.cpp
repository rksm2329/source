#include <iostream>

using namespace std;

const int MOD = 20123;

int r[10010][110][2], a[10010];

int main() {
  int n, m, x, ret = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> r[i][j][0] >> r[i][j][1];
      if (r[i][j][0] == 1) {
        ++a[i];
      }
    }
  }
  cin >> x;
  for (int i = 1; i <= n; i++) {
    ret = (r[i][x][1] + ret) % MOD;
    int s = r[i][x][1] % a[i];
    if (s == 0) {
      s = a[i];
    }
    if (r[i][x][0] == 1) {
      s--;
    }
    while (s) {
      x++;
      if (x == m) {
        x = 0;
      }
      if (r[i][x][0] == 1) {
        --s;
      }
    }
  }
  cout << ret;
  return 0;
}