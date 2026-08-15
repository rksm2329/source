#include <bits/stdc++.h>

using namespace std;

int n, ans, sna;

int main() {
  cin >> n;
  while (n) {
    ans++;
    if (!sna && n % 3 == 1) {
      sna = ans;
    }
    n -= (n + 2) / 3;
  }
  cout << ans << ' ' << sna;
  return 0;
}