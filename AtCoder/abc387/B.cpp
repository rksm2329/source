#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int x;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> x;
  int ans = 0;
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      if (i * j != x) {
        ans += i * j;
      }
    }
  }
  cout << ans;
  return 0;
}