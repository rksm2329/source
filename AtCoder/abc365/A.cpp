#include <bits/stdc++.h>

using namespace std;

int y;

int main() {
  cin >> y;
  if (y % 4 || (y % 100 == 0 && y % 400)) {
    cout << 365;
  } else {
    cout << 366;
  }
  return 0;
}