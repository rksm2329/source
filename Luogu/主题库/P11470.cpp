#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e3 + 10, Vx = 1e5;
const ll Vy = 1e12, INFy = (MAXN * Vy) << 1;

int n, m;
ll dp[(Vx << 1) + 10];
pair<ll, ll> a[MAXN];

bool C(ll x, ll y, ll z) {
  ll w = z + y - x;
  return w <= (Vx << 1) && dp[max(0ll, w)] >= z;
}

ll F(ll x, ll y) {
  ll l = -Vy, r = (Vx << 1) + x - y, ans = Vx - y;
  while (l <= r) {
    ll mid = (l + r) >> 1;
    if (C(x, y, mid)) {
      l = mid + 1;
      ans = mid;
    } else {
      r = mid - 1;
    }
  }
  return ans - Vx + y;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  memset(dp, -1e7, sizeof(dp));
  dp[Vx] = Vx;
  for (int i = 1; i <= n; i++) {
    if (a[i].first >= 0) {
      for (int j = Vx << 1; j >= a[i].first; j--) {
        dp[j] = max(dp[j], dp[j - a[i].first] + a[i].second);
      }
    } else {
      for (int j = 0; j <= a[i].first + (Vx << 1); j++) {
        dp[j] = max(dp[j], dp[j - a[i].first] + a[i].second);
      }
    }
  }
  for (int i = (Vx << 1); i >= 0; i--) {
    dp[i] = max(dp[i + 1], dp[i]);
  }
  cin >> m;
  for (ll x, y; m--; ) {
    cin >> x >> y;
    cout << F(x, y) << '\n';
  }
  return 0;
}