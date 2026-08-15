#include <bits/stdc++.h>

using namespace std;

int main() {
  int h;
  cin >> h;
  int ans = 1;
  for (int i = 1; i <= h; i = i * 2 + 1) {
    ans++;
  }
  cout << ans;
  return 0;
}