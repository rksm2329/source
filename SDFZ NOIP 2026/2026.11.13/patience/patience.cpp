#include <bits/stdc++.h>
// #define localtest

using namespace std;
using ll = long long;

const int MAXN = 1e6 + 10;

int n, a[MAXN], last[MAXN], mx[MAXN], ans[MAXN];

int main() {
  #ifndef localtest
  freopen("patience.in", "r", stdin);
  freopen("patience.out", "w", stdout);
  #endif
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mx[a[i]] = max(mx[a[i]], i - last[a[i]]), last[a[i]] = i;
  }
  fill(ans + 1, ans + n + 1, -1);
  for (int i = n, j = n; i >= 1; i--) {
    if (!mx[i]) continue;
    mx[i] = max(mx[i], n + 1 - last[i]);
    for (; j >= mx[i]; ans[j--] = i);
  }
  for (int i = 1; i <= n; cout << ans[i++] << ' ');
  return 0;
}