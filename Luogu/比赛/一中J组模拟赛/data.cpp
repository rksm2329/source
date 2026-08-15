#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  freopen("lcm.in", "w", stdout);
  cout << 1000 << '\n';
  mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
  for (int i = 1; i <= 1000; i++) {
    cout << rnd() % 10000000 + 1 << ' ' << rnd() % 10000000 + 1 << '\n';
  }
  return 0;
}