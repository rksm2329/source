#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10;

int n, a[MAXN << 1];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  bitset<MAXN << 1> dp(1);
  for (int i = 1; i <= n; i++) {
    dp |= dp >> (i - 1) << (a[i] + i - 1);
  }
  ll k = 0, ans = 0;
  for (int i = 1; i <= n << 1; i++) {
    k += a[i];
    if (dp[i - 1]) {
      ans = max(ans, k - i + 1);
    }
  }
  cout << ans;
  return 0;
}