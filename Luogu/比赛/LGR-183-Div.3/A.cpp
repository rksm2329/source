#include <bits/stdc++.h>

using namespace std;

int h, m;
char c;

int main() {
  cin >> h >> c >> m;
  if (h >= 6 && h <= 9) {
    cout << 0 << h;
  } else if (h >= 10 && h <= 23) {
    cout << h;
  } else {
    cout << 24 + h;
  }
  cout << ':';
  if (m >= 0 && m <= 9) {
    cout << 0;
  }
  cout << m;
  return 0;
}