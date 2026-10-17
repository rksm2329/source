#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;

int n, m, k, a[MAXN << 1];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[n + i] = a[i];
  }
  int ans = 0;
  for (int i = 0, j = 1, cnt = 0; j <= n << 1; j++) {
    cnt += abs(a[j] - a[j - 1]) > k;
    while (cnt > m) {
      i++, cnt -= abs(a[i] - a[i - 1]) > k;
    }
    ans = max(ans, j - i + 1);
  }
  cout << min(ans, n);
  return 0;
}