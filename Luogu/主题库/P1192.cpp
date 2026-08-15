#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 1e5 + 10, MOD = 1e5 + 3;

int f[MAXN], n, k;

int main() {
  cin >> n >> k;
  f[0] = f[1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = i - 1; j >= max(i - k, 0); j--) {
      f[i] = (f[i] + f[j]) % MOD;
    }
  }
  cout << f[n];
  return 0;
}