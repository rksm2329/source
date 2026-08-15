#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

int ans, n, a[MAXN];

int main() {
  cin >> n;
  for (int i = 1; i <= n; cin >> a[i], i++) {
  }
  int i;
  for (i = 1; i < n; ans++) {
    i += a[i];
  }
  cout << (i == n ? "Yes" : "No") << '\n' << ans;
  return 0;
}