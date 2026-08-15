#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

int n, m, a[MAXN];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int mx = 0, id = -1;
    for (int j = 1, x; j <= m; j++) {
      cin >> x;
      a[j] = x;
      if (a[j] > mx) {
        mx = a[j], id = j;
      }
    }
    int ans = 0;
    for (int j = 1; j <= id; j++) {
      ans += (a[j] && a[j] < mx);
    }
    cout << id << ' ' << ans << '\n';
  }
  return 0;
}