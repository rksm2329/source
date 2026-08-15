#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10, MAXK = 60, MOD = 1e9 + 7;

long long n, k, a[MAXN], c[MAXN][MAXK];

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= k; j++) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    }
    if (i <= 50) {
      c[i][i] = 1;
    }
  }
  long long ans = 0;
  sort(a + 1, a + n + 1);
  for (int i = k; i <= n; i++) {
    ans = (ans + c[i - 1][k - 1] * a[i] % MOD) % MOD;
  }
  cout << ans;
  return 0;
}