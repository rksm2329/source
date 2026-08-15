#include <bits/stdc++.h>
using namespace std;

int a[2010][2010], b[2010][2010], c[2010][2010], d[2010][2010];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= 2 * n; i++) {
    for (int j = 1; j <= 2 * m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= 2 * n; i++) {
    for (int j = 1; j <= m; j++) {
      b[i][j] = a[i][2 * (j - 1) + 1] + a[i][2 * j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      c[i][j] = b[2 * (i - 1) + 1][j] + b[2 * i][j];
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cout << c[j][i] << " ";
    }
    cout << '\n';
  }
  return 0;
}