#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e3 + 10;

char a[MAXN], b[MAXN];
int dp[MAXN][MAXN];

int main() {
  cin >> a >> b;
  int la = strlen(a), lb = strlen(b);
  for (int i = 1; i <= lb; i++) {
    dp[i][0] = i;
  }
  for (int i = 1; i <= la; i++) {
    dp[0][i] = i;
  }
  for (int i = 1; i <= la; i++) {
    for (int j = 1; j <= lb; j++) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
        continue;
      }
      dp[i][j] = min({dp[i - 1][j],dp[i][j - 1]}) + 1;
    }
  }
  cout << dp[la][lb];
  return 0;
}