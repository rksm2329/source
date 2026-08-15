#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int x, y, k;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> x >> y >> k;
  int ans = 0, cnt = 0;
  for (int i = 0; i <= x; i++) {
    for (int j = 1; j <= y; j++) {
      for (int l = 0; l <= k; l++) {
        if (((i + j) ^ l) > ans) {
          ans = (i + j) ^ l, cnt = 1;
        } else if (((i + j) ^ l) == ans) {
          cnt++;
        }
      }
    }
  }
  cout << ans << '\n' << cnt;
  return 0;
}