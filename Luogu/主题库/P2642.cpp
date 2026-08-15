#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

int n;
long long a[MAXN], l[MAXN], r[MAXN];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  l[1] = a[1];
  for (int i = 2; i <= n; i++) {
    l[i] = max({l[i - 1] + a[i], a[i], l[i - 1]});
  }
  r[n] = a[n];
  for (int i = n - 1; i >= 1; i--) {
    r[i] = max({r[i + 1] + a[i], a[i], r[i + 1]});
  }
  long long ans = 0;
  for (int i = 1; i <= n - 2; i++) {
    ans = max(ans, l[i] + r[i + 2]);
  }
  cout << ans;
  return 0;
}