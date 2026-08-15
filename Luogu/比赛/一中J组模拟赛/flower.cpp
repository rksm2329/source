#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, a[110];
bool v[110];

int main() {
  freopen("flower.in", "r", stdin);
  freopen("flower.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  int maxh = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    maxh = max(maxh, a[i]);
  }
  int ans = 0;
  fill(v + 1, v + n + 1, 1);
  for (int i = 0; i <= maxh; i++) {
    int mi = 2e9;
    for (int j = 1; j <= n; j++) {
      if (v[j]) {
        mi = min(mi, a[j]);
      }
    }
    int l = 0, r = 0;
    for (int j = 1; j <= n + 1; j++) {
      if (v[j] && !v[j - 1]) {
        l = j;
      } else if (!v[j] && v[j - 1]) {
        r = j - 1;
      }
      if (l && r) {
        ans++;
        l = 0, r = 0;
      }
    }
    for (int j = 1; j <= n; j++) {
      if (a[j] == mi) {
        v[j] = 0;
      }
      if (v[j]) {
        a[j] -= mi;
      }
    }
  }
  cout << ans;
  return 0;
}