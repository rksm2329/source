#include <bits/stdc++.h>

using namespace std;

bool l, r;

int main() {
  cin >> l >> r;
  if ((l || r) && !(l && r)) {
    if (l) {
      cout << "Yes";
    } else {
      cout << "No";
    }
  } else {
    cout << "Invalid";
  }
  return 0;
}