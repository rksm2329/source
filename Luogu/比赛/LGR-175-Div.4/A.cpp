#include <bits/stdc++.h>

using namespace std;

int x, y, z;

int main() {
  cin >> x >> y >> z;
  int ans = 0;
  ans += x > (y + z);
  ans += y > (x + z);
  ans += z > (x + y);
  cout << ans;
  return 0;
}