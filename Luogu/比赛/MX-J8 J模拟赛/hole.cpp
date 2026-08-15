#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;
const int MOD = 1e9 + 7;

ll n, m[MAXN], a[MAXN], b[MAXN], c[MAXN], d[MAXN];

ll Power(ll x, ll n) {
  ll ans = 1;
  for (; n; x = x * x % MOD, n /= 2) {
    if (n % 2) {
      ans = ans * x % MOD;
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> m[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    c[i] = min(a[i] - 1, m[i] - a[i]);
    d[i] = max(a[i] - 1, m[i] - a[i]);
  }
  sort(c + 1, c + n + 1);
  sort(d + 1, d + n + 1);
  for (int i = 1; i <= n; i++) {
    b[2 * i - 1] = a[i] - 1;
    b[2 * i] = m[i] - a[i];
  }
  sort(b + 1, b + 2 * n + 1);
  int l = unique(b + 1, b + 2 * n + 1) - b - 1;
  ll ans = 0;
  for (int i = 1; i <= l; i++) {
    int pos = lower_bound(d + 1, d + n + 1, b[i]) - d;
    if (pos != 1) {
      break;
    }
    pos = lower_bound(c + 1, c + n + 1, b[i]) - c;
    ll sum = Power(2, n - pos + 1);
    ans = (ans + sum * (b[i] - b[i - 1]) % MOD) % MOD;  
  }
  cout << ans + 1;
  return 0;
}