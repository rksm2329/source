#include <bits/stdc++.h>

using namespace std;

int n, x, ans, a[30], pre[30], dp[30];

void print(int i) {
  if (!i) {
    return;
  }
  print(pre[i]);
  cout << i << ' ';
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dp[i] = a[i];
  }
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dp[i]);
    for (int j = i + 1; j <= n; j++) {
      cin >> x;
      if (x == 1 && dp[i] + a[j] > dp[j]) {
        dp[j] = dp[i] + a[j];
        pre[j] = i;
      }
    }
  }
  int p = max_element(dp + 1, dp + n + 1) - dp;
  print(p);
  cout << '\n' << ans;
  return 0;
}