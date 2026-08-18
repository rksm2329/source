#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e3 + 10, MOD = 1e9 + 7;

int n, k;
int dp[MAXN][MAXN][2];
int sum[MAXN][MAXN][2];

/* 
状态：dp[i][j][k] 表示当前和为 i, 上一个数为 j, 大于上一个数或小于上一个数的方案数
转移：dp[i][j][0] -> dp[i'][j'][1]
     dp[i][j][1] -> dp[i'][j'][0]
     i' > i
初始状态: dp[0][1][0/1]
目标状态: dp[n][i][j], 1 <= i <= n, 0 <= j <= 1
拓扑序: i 从小到大
优化: 前缀和
*/

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  if (n == k) {
    cout << 1;
    return 0;
  }
  dp[k][k][0] = dp[k][k][1] = 1;
  fill(&sum[k][k][0], &sum[k][n][1], 1);
  for (int i = k; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      dp[i][j][0] = sum[i - j][j - 1][1];
      dp[i][j][1] = (sum[i - j][i][0] - sum[i - j][j][0] + MOD) % MOD;
    }
    for (int j = 1; j <= n; j++) {
      sum[i][j][0] = (sum[i][j - 1][0] + dp[i][j][0]) % MOD;
      sum[i][j][1] = (sum[i][j - 1][1] + dp[i][j][1]) % MOD;
    }
  }
  cout << (sum[n][n][0] + sum[n][n][1]) % MOD;
  return 0;
}