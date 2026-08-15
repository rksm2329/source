#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int n, a[MAXN], b[MAXN], x[MAXN];
long long dp[MAXN][2];

int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> a[i] >> b[i] >> x[i];
  } 
  for (int i = 1; i <= n; i++) {
    dp[i][0] = (dp[i][0] == 0 ? dp[i - 1][0] + a[i - 1] : min(dp[i][0], dp[i - 1][0] + a[i - 1]));
    dp[x[i - 1]][1] = (dp[x[i]][1] == 0 ? dp[i - 1][1] + b[i - 1] : min(dp[x[i - 1]][1], dp[i - 1][1] + b[i - 1]));
    cout << dp[i][0] << ' ' << dp[x[i - 1]][1] << '\n';
  }
  cout << min(dp[n][0], dp[n][1]);
  return 0;
}