#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

int t, n, a[MAXN], pos[MAXN];

void js() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  int ans = 0;
  for (int l = 1, x = 1, j; l <= n; l = x + 1) {
    for (j = x = l; j <= x; j++) {
      x = max(x, pos[j]);
    }
    if (x - l + 1 > 1) {
      ans += x - l + 1;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    js();
  }
  return 0;
}