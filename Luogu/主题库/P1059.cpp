#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 1e2 + 10;

int n, a[MAXN];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] != a[i - 1]) {
      ans++;
    }
  }
  cout << ans << '\n';
  for (int i = 1; i <= n; i++) {
    if (a[i] != a[i - 1]) {
      cout << a[i] << ' ';
    }
  }
  return 0;
}