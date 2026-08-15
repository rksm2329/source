#include <bits/stdc++.h>

using namespace std;

int a[3], b[3];

int main() {
  cin >> a[0] >> a[1];
  sort(a, a + 2);
  int ans = 0;
  for (int i = 2 * a[0] - a[1]; i <= 2 * a[1] - a[0]; i++) {
    for (int j = 0; j < 3; j++) {
      b[j] = a[j];
    }
    b[2] = i;
    sort(b, b + 3);
    if (b[1] - b[0] == b[2] - b[1]) {
      ans++;
    }
  }
  cout << ans;
  return 0;
}