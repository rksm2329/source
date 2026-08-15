#include <bits/stdc++.h>

using namespace std;

int a, b;

int main() {
  cin >> a >> b;
  if (a == b) {
    cout << -1;
  } else {
    cout << 6 - a - b;
  }
  return 0;
}