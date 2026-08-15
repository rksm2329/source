#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e6 + 10;

int n, m;
ll cnt[MAXN << 1];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 1, x, y; i <= m; i++) {
    cin >> x >> y, x--, y--;
    cnt[(x + y) % n]++;
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += cnt[i] * (m - cnt[i]);
  }
  cout << (ans >> 1);
  return 0;
}