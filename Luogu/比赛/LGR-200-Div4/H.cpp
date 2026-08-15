#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

int n, p, a[MAXN];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> p;
  for (int i = 1; i <= n; i++) {
    a[i] = (i == 1);
  }
  if (n * 9 < p) {
    for (int i = 1; i <= n; i++) {
      cout << a[i];
    }
    return 0;
  }
  int x = (p - 1) / 9;
  for (int i = n; i >= (n - x + 1); i--) {
    a[i] = 9;
  }
  a[n - x] += (p - 1) % 9;
  for (int i = 1; i <= n; i++) {
    cout << a[i];
  }
  return 0;
}