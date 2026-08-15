#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 10;

long long n, m, q, a[MAXN], b[MAXN][MAXN], age[MAXN][MAXN];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    age[0][i] = a[i];
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> b[i][j];
      age[i][j] = age[i - 1][j] + b[i][j];
    }
  }
  for (int x, y, z; q--; ) {
    cin >> x >> y >> z;
    cout << age[x][y] - age[x][z] << '\n';
  }
  return 0;
}