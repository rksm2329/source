#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 10, MAXV = 1e7 + 10;

int t, m, a[MAXN], b[MAXN];
long long dp[MAXV];

int main() {
  cin >> t >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 1; i <= m; i++) {
    for (int j = a[i]; j <= t; j++) {
      dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
    }
  }
  cout << dp[t];
  return 0;
}