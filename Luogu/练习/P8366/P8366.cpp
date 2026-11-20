#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 20, MOD = 1e9 + 7;

int n, dp[2][MAXN][MAXN][MAXN][MAXN][MAXN][MAXN];
string s;

void Solve() {
  cin >> n >> s;
  s = '#' + s;
  dp[0][0][0][0][0][0][0] = 1;
  for (int i = 1; i <= 3 * n; i++) {
    int last = 3 * n - i + 1;
    for (int a = 0; a <= min(n, i) && 2 * a <= last; a++) {
      for (int b = 0; a + b <= min(n, i) && 2 * (a + b) <= last; b++) {
        for (int c = 0; a + b + c <= min(n, i) && 2 * (a + b + c) <= last; c++) {
          for (int d = 0; a + b + c + d <= n && a + b + c + 2 * d <= i && 2 * (a + b + c) + d <= last; d++) {
            for (int e = 0; a + b + c + d + e <= n && a + b + c + 2 * (d + e) <= i && 2 * (a + b + c) + d + e <= last; e++) {
              for (int f = 0; a + b + c + d + e + f <= n && a + b + c + 2 * (d + e + f) <= i && 2 * (a + b + c) + d + e + f <= last; f++) {
                dp[i & 1][a][b][c][d][e][f] = 0;
              }
            }
          }
        }
      }
    }
    for (int a = 0; a <= min(n, i) && 2 * a <= last; a++) {
      for (int b = 0; a + b <= min(n, i) && 2 * (a + b) <= last; b++) {
        for (int c = 0; a + b + c <= min(n, i) && 2 * (a + b + c) <= last; c++) {
          for (int d = 0; a + b + c + d <= n && a + b + c + 2 * d <= i && 2 * (a + b + c) + d <= last; d++) {
            for (int e = 0; a + b + c + d + e <= n && a + b + c + 2 * (d + e) <= i && 2 * (a + b + c) + d + e <= last; e++) {
              for (int f = 0; a + b + c + d + e + f <= n && a + b + c + 2 * (d + e + f) <= i && 2 * (a + b + c) + d + e + f <= last; f++) {
                ll pre = dp[(i - 1) & 1][a][b][c][d][e][f];
                if (!pre) continue;
                if (s[i] == '1' || s[i] == '0') {
                  if (a < n) (dp[i & 1][a + 1][b][c][d][e][f] += pre) %= MOD;
                  if (b && d < n) (dp[i & 1][a][b - 1][c][d + 1][e][f] += pre * b % MOD) %= MOD;
                  if (f) (dp[i & 1][a][b][c][d][e][f - 1] += pre * f % MOD) %= MOD;
                }
                if (s[i] == '2' || s[i] == '0') {
                  if (b < n) (dp[i & 1][a][b + 1][c][d][e][f] += pre) %= MOD;
                  if (c && f < n) (dp[i & 1][a][b][c - 1][d][e][f + 1] += pre * c % MOD) %= MOD;
                  if (e) (dp[i & 1][a][b][c][d][e - 1][f] += pre * e % MOD) %= MOD;
                }
                if (s[i] == '3' || s[i] == '0') {
                  if (c < n) (dp[i & 1][a][b][c + 1][d][e][f] += pre) %= MOD;
                  if (a && e < n) (dp[i & 1][a - 1][b][c][d][e + 1][f] += pre * a % MOD) %= MOD;
                  if (d) (dp[i & 1][a][b][c][d - 1][e][f] += pre * d % MOD) %= MOD;
                }
              }
            }
          }
        }
      }
    }
  }
  ll ans = dp[n & 1][0][0][0][0][0][0];
  for (int i = 1; i <= n; i++) (ans *= i) %= MOD;
  cout << ans << '\n';
  memset(dp, 0, sizeof dp);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  for (cin >> T; T--; Solve());
  return 0;
}