
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 4e18;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n + 2), dp(n + 2), v;
  vector<int> key(n + 2), ask(n + 2);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    key[i] = v.size();
    v.push_back(i - a[i]);
    v.push_back(i + a[i] + 1);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  auto get = [&](ll x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
  };
  vector<int> id1(n + 2), id2(n + 2);
  for (int i = 1; i <= n; i++) {
    id1[i] = get(i - a[i]);
    id2[i] = get(i + a[i] + 1);
  }
  vector<ll> best(v.size(), INF);
  dp[n + 1] = 0;
  for (int i = n; i >= 1; i--) {
    if (i < n) {
      best[id1[i + 1]] = min(best[id1[i + 1]], dp[i + 2]);
    }
    dp[i] = dp[i + 1] + 1;
    dp[i] = min(dp[i], best[id2[i]]);
  }
  cout << dp[1] << '\n';
  return 0;
}
