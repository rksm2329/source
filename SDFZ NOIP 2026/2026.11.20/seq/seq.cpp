#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const int MAXN = 2e5 + 10;

int n, k;
pll a[MAXN];

int main() {
  freopen("seq.in", "r", stdin);
  freopen("seq.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> k;
  ll tot = 0;
  for (int i = 1; i <= n; i++) {
    auto &[sum, len] = a[i];
    cin >> len;
    vector<ll> arr(len + 1);
    for (int j = 1; j <= len; j++) {
      cin >> arr[j];
      sum += arr[j], tot += arr[j] * j;
    }
  }
  sort(a + 1, a + n + 1);
  int l = 0;
  for (int i = 1; i <= n; i++) {
    auto &[sum, len] = a[i];
    tot += l * sum, l += len;
  }
  if (k == 1) {
    cout << tot;
    return 0;
  }
  l = 0;
  ll ans = 0;
  for (int i = 1; i < n; i++) {
    auto &[sum1, len1] = a[i];
    auto &[sum2, len2] = a[i + 1];
    ll ktot = tot;
    ktot -= l * sum1 + (l + len1) * sum2;
    ktot += l * sum2 + (l + len2) * sum1;
    ans = max(ans, ktot), l += len1;
  }
  cout << ans;
  return 0;
}