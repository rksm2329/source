#include <bits/stdc++.h>

using namespace std;

int r;

int main() {
  cin >> r;
  if (r >= 1 && r <= 99) {
    cout << 100 - r;
  } else if (r >= 100 && r <= 199) {
    cout << 200 - r;
  } else if (r >= 200 && r <= 299) {
    cout << 300 - r;
  }
  return 0;
}