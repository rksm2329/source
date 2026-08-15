#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;

int n, ans, a[MAXN];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("data.in", "r", stdin);
  freopen("out1.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      bool f = 1;
      for (int k = i + 2; k <= j; k++) {
        if (a[k] - a[k - 1] != a[k - 1] - a[k - 2]) {
          f = 0;
          break;
        }
      }
      if (f) {
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}