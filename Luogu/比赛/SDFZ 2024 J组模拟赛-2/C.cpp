#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10, MAXV = 5e7 + 10;

int n, p, k, a[MAXN], dp[MAXV];
pair<int, int> b[MAXN];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> p >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int tot = 0;
  for (int i = 0; i < n; i++) {
    if (i % k == k - 1) {
      b[++tot] = {2 * a[i], k};
    }
  }
  for (int i = n - n % k; i < n; i++) {
    b[++tot] = {a[i], 1};
  }
  for (int i = 1; i <= tot; i++) {
    for (int j = p; j >= b[i].first; j--) {
      dp[j] = max(dp[j], dp[j - b[i].first] + b[i].second);
    }
  }
  cout << dp[p];
  return 0;
}