#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e7 + 10;

int l, r;

int gcd(int x, int y) {
  return !y ? x : gcd(y, x % y);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> l >> r;
  int ans = 0;
  for (int i = l; i <= r; i++) {
    for (int j = i + 1; j <= r; j++) {
      ans = max(ans, gcd(i, j));
    }
  }
  cout << ans;
  return 0;
}