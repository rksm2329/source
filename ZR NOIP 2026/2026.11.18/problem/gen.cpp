#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  freopen("1.in", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cout << 5000 << '\n';
  mt19937_64 rnd(time(nullptr));
  for (int i = 1; i <= 5000; i++) {
    cout << rnd() % (1 << 7) << ' ';
  }
  return 0;
}