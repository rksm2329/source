#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e2 + 10;

int n, a[MAXN];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    cout << 1ll * a[i] * a[i + 1] << ' ';
  }
  return 0;
}