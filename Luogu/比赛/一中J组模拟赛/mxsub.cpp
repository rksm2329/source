#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10;

int n, a[MAXN];

int main() {
  freopen("mxsub.in", "r", stdin);
  freopen("mxsub.in", "r", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int mx = 0, mi = 2e9;
    for (int j = i; j <= n; j++) {
      mx = max(mx, a[j]);
      mi = min(mi, a[j]);
      ans = max(ans, mx - mi - (j - i + 1));
    }
  }
  cout << ans;
  return 0;
}