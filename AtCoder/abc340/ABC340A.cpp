#include <bits/stdc++.h>

using namespace std;

int a, b, d;

int main() {
  cin >> a >> b >> d;
  for (int i = a; i <= b; i += d) {
    cout << i << ' ';
  }
  return 0;
}