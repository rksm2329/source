#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int m, ans = INT_MAX;
string a, b, c;

int main() {
  cin >> m >> a >> b >> c;
  a += a + a, b += b + b, c += c + c;
  for (int i = 1; i <= 3 * m; i++) {
    for (int j = 1; j <= 3 * m; j++) {
      for (int k = 1; k <= 3 * m; k++) {
        if (!(i == j || i == k || j == k) && a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1] && a[i - 1] == c[k - 1]) {
          ans = min(ans, max({i, j, k}) - 1);
        }
      }
    }
  }
  if (ans == INT_MAX) {
    ans = -1;
  }
  cout << ans;
  return 0;
}