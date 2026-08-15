#include <bits/stdc++.h>

using namespace std;

int n, a[110][110];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cin >> a[i][j];
    }
  }
  int element = 1;
  for (int i = 1; i <= n; i++) {
    if (element >= i) {
      element = a[element][i];
    } else {
      element = a[i][element];
    }
  }
  cout << element;
  return 0;
}