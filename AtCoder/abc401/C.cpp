#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e6 + 10, MOD = 1e9;

int n, k;
ll a[MAXN], sum[MAXN];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  sum[0] = 1;
  for (int i = 0; i < k; i++) {
    a[i] = 1;
    if (i > 0) sum[i] = sum[i - 1] + a[i];
  }
  for (int i = k; i <= n; i++) {
    a[i] = sum[i - 1];
    if (i > k) a[i] = (a[i] - sum[i - k - 1] + MOD) % MOD;
    sum[i] = (sum[i - 1] + a[i]) % MOD;
  }
  cout << a[n];
  return 0;
}