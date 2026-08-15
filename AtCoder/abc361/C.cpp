#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int n, k, a[MAXN];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int ans = INT_MAX;
  for (int i = 1; i <= k + 1; i++) {
    ans = min(ans, a[i + (n - k) - 1] - a[i]);
  }
  cout << ans;
  return 0;
}