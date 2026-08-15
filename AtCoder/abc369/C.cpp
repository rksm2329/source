#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;

int n, a[MAXN];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = n; i >= 1; i--) {
    a[i] -= a[i - 1];
  }
  a[1] = 0;
  ll cnt = 0, last = 1, ans = n + n - 1;
  for (int i = 1; i <= n; i++) {
    if (i == 1 || a[i] == a[i - 1]) {
      cnt++;
    } else {
      if (last != 1) {
        cnt++;
      }
      ans += cnt * (cnt + 1) / 2 - cnt - cnt + 1;
      last = i;
      cnt = 1;
    }
  }
  if (cnt > 1) {
    ans += cnt * (cnt + 1) / 2 - cnt - cnt + 1 + (last != 1) * (cnt - 1);
  }
  cout << ans;
  return 0;
}