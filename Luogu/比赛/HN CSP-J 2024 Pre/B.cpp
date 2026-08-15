#include <bits/stdc++.h>

using namespace std;

int n, a[10];

int main() {
  cin >> n;
  unsigned long long ans = 0;
  unsigned long long t = 1;
  for (int i = 1; i <= n; i++) {
    t *= i;
    ans += t;
  }
  int tot = 0;
  for (; ans; ans /= 10) {
    a[++tot] = ans % 10;
    if (tot == 8) {
      break;
    }
  }
  for (int i = tot; i >= 1; i--) {
    if (!a[i]) {
      tot--;
    } else {
      break;
    }
  }
  for (int i = tot; i >= 1; i--) {
    cout << a[i];
  }
  return 0;
}