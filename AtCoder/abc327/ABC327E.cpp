#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e3 + 10, INF = 6e3;

int n, a[MAXN];

double ans = -INF, dp[MAXN][MAXN];

double getSum(int x) {
  double sum = 0;
  for (int i = 0; i < x; i++) {
    sum += pow(0.9, i);
  }
  return sum;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = n; i; i--) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = dp[i + 1][j], dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + pow(0.9, j - 1) * a[i]);
    }
  }
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dp[1][i] / getSum(i) - 1200 / sqrt(i));
  }
  cout << fixed << setprecision(6) << ans;
  return 0;
}