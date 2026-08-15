#include <bits/stdc++.h>

using namespace std;

int a;

int main() {
  cin >> a;
  if (!a) {
    cout << 0;
    return 0;
  }
  for (int i = 1; ; i++) {
    if (floor(10 * sqrt(i)) >= a) {
      cout << i;
      return 0;
    }
  }
  return 0;
}