#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e3 + 10;

int n, m, d, a[MAXN][MAXN];
vector<pair<int, int>> v;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> d;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      if (c == '#') {
        a[i][j] = 0;
      } else if (c == '.') {
        a[i][j] = 1;
      } else {
        a[i][j] = 2;
        v.push_back({i, j});
        ans++;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 1) {
        for (int k = 0; k < v.size(); k++) {
          
        }
      }
    }
  }
  return 0;
}