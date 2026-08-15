#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e4 + 10;

int dp[MAXN];
int a[40];

int main() {
  int n, m;
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= a[i]; j--) {
      dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
    }
  }
  cout << m - dp[m];
  return 0;
}