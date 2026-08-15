#include <bits/stdc++.h>

using namespace std;
using ll = long long;

double n;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  if (n >= 38.0) {
    cout << 1;
  } else if (n >= 37.5) {
    cout << 2;
  } else {
    cout << 3;
  }
  return 0;
}