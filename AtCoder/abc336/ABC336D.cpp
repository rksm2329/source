#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int n, a[MAXN], b[MAXN][2];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    b[i][0] = a[i] > a[i - 1] ? b[i - 1][0] + 1 : min(a[i], b[i - 1][0] + 1);
  }
  for (int i = n; i >= 1; i--) {
    b[i][1] = a[i] > a[i + 1] ? b[i + 1][1] + 1 : min(a[i], b[i + 1][1] + 1);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, min(b[i][0], b[i][1]));
  }
  cout << ans;
  return 0;
}