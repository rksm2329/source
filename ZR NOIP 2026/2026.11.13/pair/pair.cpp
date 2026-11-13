#include <bits/stdc++.h>
// #define localtest

using namespace std;
using ll = long long;

const int MAXN = 2e6 + 10;

int n, k, a[MAXN];
bool del[MAXN];

int main() {
  #ifndef localtest
  freopen("pair.in", "r", stdin);
  freopen("pair.out", "w", stdout);
  #endif
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; cin >> a[i++]);
  sort(a + 1, a + n + 1);
  int ans = 0;
  for (int l = 1, r = n / 2 + 1; l <= n && r <= n; ) {
    for (; l <= n && del[l]; l++);
    for (; r <= n && del[r]; r++);
    if (l > n || r > n) break;
    if (l < r && a[r] - a[l] >= k) {
      del[l] = del[r] = 1, ans++, l++, r++;
    } else r++;
  }
  cout << ans;
  return 0;
}