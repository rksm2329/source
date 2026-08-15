#include <bits/stdc++.h>

using namespace std;

int a, b, r, v, m;

int main() {
  cin >> b >> a >> r >> v >> m;
  cout << a * r + b * r * 4 << ' ' << a * v + b * v * 6 << ' ' << a * m + b * m * 6;
  return 0;
}