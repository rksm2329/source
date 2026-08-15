#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-6;

double a, b, c, d;
double ans[3];
int cnt;

double F(double x) {
  return a * x * x * x + b * x * x + c * x + d;
}

int main() {
  cin >> a >> b >> c >> d;
  cout << fixed << setprecision(2);
  for (int i = -100; i <= 100; i++) {
    if (F(i) > -eps && F(i) < eps) {
      ans[cnt++] = i;
      continue;
    }
    double l = i + eps, r = i + 1 - eps;
    if (F(l) * F(r) < 0) {
      while (r - l > eps) {
        double mid = (l + r) / 2;
        if (F(mid) * F(l) < 0) {
          r = mid;
          ans[cnt] = mid;
        } else {
          l = mid;
        }
      }
      cnt++;
    }
  }
  cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
  return 0;
}