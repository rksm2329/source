#include <bits/stdc++.h>

using namespace std;

int n, k, p, q;

int gcd(int x, int y) {
  return !y ? x : gcd(y, x % y);
}

int lcm(int x, int y) {
  return x / gcd(x, y) * y;
}

int main() {
  cin >> n >> k >> p >> q;
  int l = lcm(n, q);
  k *= l / n;
  p *= l / q;
  cout << max(0, (k - p + l / n - 1) / (l / n));
  return 0;
}