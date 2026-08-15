#include <bits/stdc++.h>

using namespace std;

int x, y, w, k;

int main() {
  cin >> x >> y >> w >> k;
  int sum = 0, i;
  for (i = 1; sum < k; i++) {
    sum += i / w + (i >= x) * y;
  }
  cout << i - 1;
  return 0;
}