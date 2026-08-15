#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;

ll n, a[MAXN];
pair<ll, ll> s1[MAXN], s2[MAXN];

int main() {
  freopen("delete.in", "r", stdin);
  freopen("delete.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s1[i].first = s1[i - 1].first + (i % 2) * a[i];
    s1[i].second = s1[i - 1].second + (i % 2 == 0) * a[i];
  }
  for (int i = n; i >= 1; i--) {
    s2[i].first = s2[i + 1].first + (i % 2) * a[i];
    s2[i].second = s2[i + 1].second + (i % 2 == 0) * a[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (s1[i - 1].first + s2[i + 1].second == s1[i - 1].second + s2[i + 1].first) {
      ans++;
    }
  }
  cout << ans;
  return 0;
}