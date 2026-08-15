#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {
  cin >> n >> k;
  for (long long i = n + 1; ; i++) {
    if (i % k == 0) {
      cout << i;
      return 0;
    }
  }
  return 0;
}