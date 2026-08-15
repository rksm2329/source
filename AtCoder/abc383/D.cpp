#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n;

int sss(ll x) {
  int cnt = 0;
  for (ll i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      cnt += 2;
      if (i == x / i) cnt--;
    }
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  int ans = 0;
  for (ll i = 1; i * i <= n; i++) {
    if (sss(i * i) == 9) {
      ans++;
    }
  }
  cout << ans;
  return 0;
}