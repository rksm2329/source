#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 998244353;

int n;

int main() {
  freopen("perm.in", "r", stdin);
  freopen("perm.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  ll cnt = !(n & 1), ans = 1;
  for (int i = 1, x; i <= n; i++) {
    cin >> x;
    if (x == 1) cnt++;
    else {
      ans = ans * (cnt - 1) % MOD * (cnt - 1 + (n & 1)) % MOD, cnt--;
    }
  }
  cout << (cnt != 1 ? 0 : ans);
  return 0;
}