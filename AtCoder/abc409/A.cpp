#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e2 + 10;

int n, a[MAXN];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; cin >> a[i++]);
  sort(a + 1, a + n + 1);
  for (int i = n; i >= 0; i--) {
    int k = lower_bound(a + 1, a + n + 1, i) - a;
    if (n - k + 1 >= i) {
      cout << i;
      return 0;
    }
  }
  return 0;
}