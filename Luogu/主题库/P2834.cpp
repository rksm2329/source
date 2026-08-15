#include <iostream>

using namespace std;

const int MAXN = 1e3 + 10, MAXW = 1e4 + 10, MOD = 1e9 + 7;

int n, w, a[MAXN], dp[MAXW];

int main() {
  cin >> n >> w;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = a[i]; j <= w; j++) {
      dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
    }
  }
  cout << dp[w];
  return 0;
}