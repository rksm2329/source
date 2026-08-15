#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 55;

int n;
bool a[MAXN][MAXN];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int j = n - i + 1;
    if (i <= j) {
      for (int k = i; k <= j; k++) {
        a[i][k] = a[j][k] = a[k][i] = a[k][j] = i % 2;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << (a[i][j] ? '#' : '.');
    }
    cout << '\n';
  }
  return 0;
}