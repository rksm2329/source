#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, x, y;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> x >> y;
  if (abs(x - y) < n - max(x, y) + min(x, y)) {
    cout << (x > y ? "Counter-clockwise Loop" : "Clockwise Loop");
  } else if (n - max(x, y) + min(x, y) < abs(x - y)) {
    cout << (x > y ? "Clockwise Loop" : "Counter-clockwise Loop");
  } else {
    cout << "\"Wonderful\"";
  }
  return 0;
}