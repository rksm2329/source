#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  int l = 0, r = 0;
  int l1 = 0, l2 = 0;
  for (int i = 1, x; i <= n; i++) {
    cin >> x;
    char c;
    cin >> c;
    if (c == 'L') {
      if (l1) {
        l += abs(l1 - x);
      }
      l1 = x;
    } else {
      if (l2) {
        r += abs(l2 - x);
      }
      l2 = x;
    }
  }
  cout << l + r;
  return 0;
}