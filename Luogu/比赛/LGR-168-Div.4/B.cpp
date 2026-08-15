#include <bits/stdc++.h>

using namespace std;

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> x2 >> y1 >> y2;
  long long a = 1ll * x1 * y1;
  long long b = 1ll * x2 * y2;
  if (a > INT_MAX || b > INT_MAX) {
    cout << "long long ";
  }
  cout << "int";
  return 0;
}