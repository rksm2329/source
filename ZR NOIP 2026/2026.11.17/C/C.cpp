#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 5e5 + 10;

int n, m, k, a[MAXN];
ll pre[MAXN];

int main() {
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> k;
  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
    pre[i] = pre[i - 1] + max(0, a[i] - k);
  }
  ll ans = 0;
  for (int l = 1; l + m - 1 <= n; l++) {
    int r = l + m - 1;
    ans = max(ans, pre[r] - pre[l - 1]);
  }
  cout << sum - ans;
  return 0;
}