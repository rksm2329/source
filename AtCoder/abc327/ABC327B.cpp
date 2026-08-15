#include <bits/stdc++.h>

using namespace std;

long long b;

long long poww(int a, int b) {
  long long ans = 1;
  for (int i = 1; i <= b; ans *= a, i++) {
  }
  return ans;
}

int main() {
  cin >> b;
  for (int i = 1; i <= 15; i++) {
    long long s = 1ll * poww(i, i);
    if (s == b) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
  return 0;
}