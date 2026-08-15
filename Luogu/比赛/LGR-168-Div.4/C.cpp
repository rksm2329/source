#include <bits/stdc++.h>

using namespace std;

int n, k, ans;

int s(int x) {
  int ans = 1;
  for (int i = 1; i <= x; ans *= x, i++) {
  }
  return ans;
}

int main() {
  cin >> n >> k;
  int m = s(n);
  for (int i = n; i <= m; ans += (i % k % n == 0 && i % 10 == n), i += 10) {
  }
  cout << ans;
  return 0;
}