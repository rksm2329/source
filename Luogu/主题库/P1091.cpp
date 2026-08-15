#include <bits/stdc++.h>

using namespace std;

int g[105], f[105], a[105], s[105];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    f[i] = 1;
    g[i] = 1;
  }
  for (int i = n - 1; i >= 1; i--) {
    for (int j = i + 1; j <= n; j++) {
      if (a[i] > a[j] && f[i] <= f[j] + 1) {
        f[i] = f[j] + 1;
      }
    }
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (a[i] > a[j] && g[i] <= g[j] + 1) {
        g[i] = g[j] + 1;
      }
    }
  }
  int maxx = 0;
  for (int i = 1; i <= n; i++) {
    s[i] = f[i] + g[i] - 1;
    if (s[i] > maxx) {
      maxx = s[i];
    }
  }
  cout << n - maxx;
  return 0;
}