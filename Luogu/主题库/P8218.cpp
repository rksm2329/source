#include <iostream>

using namespace std;

const int MAXN = 1e5 + 10;

int n, m, l, r, a[MAXN], sum[MAXN];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  cin >> m;
  while (m--) {
    cin >> l >> r;
    cout << sum[r] - sum[l - 1] << '\n';
  }
  return 0;
}