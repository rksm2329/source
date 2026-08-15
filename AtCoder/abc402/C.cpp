#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 3e5 + 10;

int n, m, a[MAXN], ans[MAXN];
vector<int> v[MAXN];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 1, len, x; i <= m; i++) {
    for (cin >> len; len--; cin >> x, v[i].push_back(x));
  }
  for (int i = 1, x; i <= n; i++) {
    cin >> x;
    a[x] = i;
  }
  for (int i = 1; i <= m; i++) {
    int mx = 0;
    for (int j : v[i]) {
      mx = max(mx, a[j]);
    }
    ans[mx]++;
  }
  for (int i = 1; i <= n; i++) {
    cout << (ans[i] += ans[i - 1]) << '\n';
  }
  return 0;
}