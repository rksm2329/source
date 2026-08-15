#include <bits/stdc++.h>

using namespace std;

int a, b, c, d, m;

int main() {
  cin >> a >> b >> c >> d >> m;
  cout << (c * 5 <= m ? max(0, c * 5 - (b - d) * 20) : max(0, c * 5 + d * 20 - (b - d) * 20));
  return 0;
}