#include <bits/stdc++.h>

using namespace std;

int n, m, k;
char a[110][110];

int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int y = 1; y <= k; y++) {
      for (int j = 1; j <= m; j++) {
        for (int x = 1; x <= k; x++) {
          cout << a[i][j];
        }
      }
      cout << '\n';
    }
  }
  return 0;
}