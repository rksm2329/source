#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
map<pair<int, int>, bool> mp;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  int ans = 0;
  for (int i = 1, u, v; i <= m; i++) {
    cin >> u >> v;
    if (u == v) {
      ans++;
    } else {
      ans += mp[{u, v}] || mp[{v, u}];
      mp[{u, v}] = mp[{v, u}] = 1;
    }
  }
  cout << ans;
  return 0;
}