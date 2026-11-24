#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 4e18;

ll a, b;

int main() {
  freopen("multiple.in", "r", stdin);
  freopen("multiple.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> a >> b;
  ll ans = INF;
  for (int i = 1; i <= 50000000; i++) {
    ans = min(ans, abs(b - i) + (a <= i ? i - a % i : min(a % i, i - a % i)));
  }
  cout << ans;
  return 0;
}