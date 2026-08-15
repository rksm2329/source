#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e3 + 10;

struct Node {
  int x, y, z;
} a[MAXN];

int n, d[MAXN][MAXN];

int main() {
  ios::sync_with_stdio(), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y >> a[i].z;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i != j) {
        d[i][j] = min({abs(a[i].x - a[j].x), abs(a[i].y - a[j].y), abs(a[i].z - a[j].z)});
      }
    }
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans += d[i][j];
    }
  }
  cout << ans / 2;
  return 0;
}