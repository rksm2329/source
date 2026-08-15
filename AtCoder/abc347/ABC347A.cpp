#include <bits/stdc++.h>

using namespace std;

int n, k, a[110];

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] % k == 0) {
      cout << a[i] / k << ' ';
    }
  }
  return 0;
}