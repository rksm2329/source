#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 3e5 + 10;

int n, l, d[MAXN];
ll cnt[MAXN];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> l;
  cnt[0] = 1;
  for (int i = 2; i <= n; i++) {
    cin >> d[i];
    (d[i] += d[i - 1]) %= l;
    cnt[d[i]]++;
  }
  if (l % 3) {
    cout << 0;
    return 0;
  }
  int _l = l / 3;
  ll ans = 0;
  for (int i = 0; i < _l; i++) {
    ans += cnt[i] * cnt[i + _l] * cnt[i + (_l << 1)];
  }
  cout << ans;
  return 0;
}