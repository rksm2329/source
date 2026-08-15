#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int n, m, k, ans = INT_MAX;
string s[MAXN];
int sum1[MAXN], sum2[MAXN];

int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = ' ' + s[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      sum1[j] = sum1[j - 1] + (s[i][j] == 'x');
      sum2[j] = sum2[j - 1] + (s[i][j] == '.');
    }
    for (int j = 1; j <= m - k + 1; j++) {
      if (!(sum1[j + k - 1] - sum1[j - 1])) {
        ans = min(ans, sum2[j + k - 1] - sum2[j - 1]);
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      sum1[j] = sum1[j - 1] + (s[j][i] == 'x');
      sum2[j] = sum2[j - 1] + (s[j][i] == '.');
    }
    for (int j = 1; j <= n - k + 1; j++) {
      if (!(sum1[j + k - 1] - sum1[j - 1])) {
        ans = min(ans, sum2[j + k - 1] - sum2[j - 1]);
      }
    }
  }
  cout << (ans == INT_MAX ? -1 : ans);
  return 0;
}