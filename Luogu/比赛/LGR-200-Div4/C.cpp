#include <bits/stdc++.h>

using namespace std;

long long n;
double m;

int main() {
  cin >> n >> m;
  m /= 100;
  for (int i = 1; i <= n; i++) {
    if (fabs(1.0 * i / (n * (n + 1) / 2) - m) == 1.0 * i / (n * (n + 1) / 2) - m) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
  return 0;
}