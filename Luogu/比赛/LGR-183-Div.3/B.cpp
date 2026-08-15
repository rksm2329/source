#include <bits/stdc++.h>

using namespace std;

double dist(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double heron(double I, double J, double K, double C) {
  return sqrt(C * (C - I) * (C - J) * (C - K));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  double l, r, x1, y1, x2, y2, x3, y3;
  cout << fixed << setprecision(12);
  cin >> l >> r >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  double ans = 1e10;
  for (int i = l * 100; i <= r * 100; i++) {
    double p = i * 1.0 / 100;
    double xf = x1 + (x2 - x1) * p;
    double yf = y1 + (y2 - y1) * p;
    double xd = x2 + (x3 - x2) * p;
    double yd = y2 + (y3 - y2) * p;
    double xe = x3 + (x1 - x3) * p;
    double ye = y3 + (y1 - y3) * p;
    double I = dist(xf, yf, xd, yd);
    double J = dist(xd, yd, xe, ye);
    double K = dist(xe, ye, xf, yf);
    double C = (I + J + K) / 2;
    ans = min(ans, heron(I, J, K, C));
  }
  cout << ans;
  return 0;
}