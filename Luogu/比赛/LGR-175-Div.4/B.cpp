#include <bits/stdc++.h>

using namespace std;

double a, b, c, d, e, x, y;

int main() {
  cin >> a >> b >> c >> d >> e >> x >> y;
  double lb1 = a * x + b * y;
  double lb2 = c * y;
  double lb3 = d * y + e;
  double mx = max({lb1, lb2, lb3});
  if (mx == lb1) {
    cout << 1 << ' ' << fixed << setprecision(2) << lb1;
  } else if (mx == lb2) {
    cout << 2 << ' ' << fixed << setprecision(2) << lb2;
  } else {
    cout << 3 << ' ' << fixed << setprecision(2) << lb3;
  }
  return 0;
}