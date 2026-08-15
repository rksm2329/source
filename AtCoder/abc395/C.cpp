#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10, MAXV = 1e6 + 10;

int n, a[MAXN];
vector<int> v[MAXV];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    v[a[i]].push_back(i);
  }
  int ans = 2e9;
  for (int i = 1; i < MAXV; i++) {
    for (int j = 1; j < v[i].size(); j++) {
      ans = min(ans, v[i][j] - v[i][j - 1] + 1);
    }
  }
  cout << (ans == 2e9 ? -1 : ans);
  return 0;
}