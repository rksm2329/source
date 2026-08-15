#include <bits/stdc++.h>

using namespace std;

int m, n, a[25];

int main() {
  cin >> m;
  for (int i = 0; m; m /= 3, i++) {
    for (int j = 1; j <= m % 3; j++) {
      a[++n] = i;
    }
  }
  cout << n << '\n';
  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
  return 0;
}