#include <iostream>

using namespace std;

const int MAXN = 1e5 + 10;

long long n, x, ans, t, a[MAXN];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] + a[i - 1] > x) {
      t = a[i] + a[i - 1] - x;
      a[i] -= t;
      ans += t;
    }
  }
  cout << ans;
  return 0;
}