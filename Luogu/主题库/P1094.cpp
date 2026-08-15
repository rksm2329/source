#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 3e4 + 10;

int w, n, ans, a[MAXN];

int main() {
  cin >> w >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int l = 1, r = n; l <= r; l++) {
    for (; a[l] + a[r] > w; r--, ans++) {
    }
    r--, ans++;
  }
  cout << ans;
  return 0;
}