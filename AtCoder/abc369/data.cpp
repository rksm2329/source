#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("data.in", "w", stdout);
  cout << 3000 << '\n';
  mt19937_64 rnd(time(nullptr));
  for (int i = 1; i <= 3000; i++) {
    cout << (rnd() % 1000000000 + 1 + i) % 1000000000 + 1 << ' ';
  }
  return 0;
}