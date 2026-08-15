#include <bits/stdc++.h>

using namespace std;

int a, b, c, d;

int main() {
  cin >> a >> b >> c >> d;
  if (a + b < c + d) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  return 0;
}