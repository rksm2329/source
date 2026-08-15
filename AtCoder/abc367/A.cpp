#include <bits/stdc++.h>

using namespace std;

int a, b, c;

int main() {
  cin >> a >> b >> c;
  if (c < b) {
    c += 24;
  }
  int tme = c - b, cnt = 0;
  for (int i = b; cnt <= tme; i = (i + 1) % 24, cnt++) {
    if (i == a) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}