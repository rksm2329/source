#include <bits/stdc++.h>

using namespace std;

int n, r;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> r;
  for (int i = 1, d, a; i <= n; i++) {
    cin >> d >> a;
    if (d == 1 && r >= 1600 && r <= 2799) {
      r += a;
    } else if (d == 2 && r >= 1200 && r <= 2399) {
      r += a;
    }
  }
  cout << r;
  return 0;
}