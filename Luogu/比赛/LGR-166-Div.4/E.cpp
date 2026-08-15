#include <bits/stdc++.h>

using namespace std;

long long n, s, m;

void C(long long a, long long b, long long c, long long d) {
  if ((long long)((long double)(10000000.0) / n * a + b +
                  c * ((long double)(10000000.0) / n / 2)) != s) {
    return;
  }
  cout << "p" << a << "(+" << b << ") f" << c << " l" << d;
}

int main() {
  cin >> n >> s >> m;
  for (int j = 0; j <= n - (n - m); j++) {
    for (int ok = 0; ok <= (n - m); ok++) {
      C(n - m, ok, j, m - j);
    }
  }
  return 0;
}