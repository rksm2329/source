#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

const int MAXN = 3e3 + 10;

int n, m, sum, ans = INT_MAX, a[MAXN];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i < m) {
      sum += a[i];
    }
  }
  for (int i = 1, j = i + m - 1; j <= n; i++, j++) {
    sum += a[j];
    ans = min(ans, sum);
    sum -= a[i];
  }
  cout << ans;
  return 0;
}