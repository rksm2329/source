#include <bits/stdc++.h>

using namespace std;

int n, m, a[110], b[210], c[510];

int main() {
  cin >> n >> m;
  int x = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    c[++x] = a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    c[++x] = b[i];
  }
  sort(c + 1, c + x + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      for (int k = 1; k < x; k++) {
        if (a[i] == c[k] && a[j] == c[k + 1] || a[i] == c[k + 1] && a[j] == c[k]) {
          cout << "Yes";
          return 0;
        }
      }
    }
  }
  cout << "No";
  return 0;
}