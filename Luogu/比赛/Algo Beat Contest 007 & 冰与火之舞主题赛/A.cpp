#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll a, b, c;

bool Check() {
  return a * c + b * c + 2 * c * sqrtl(a * b) <= a * b;
}

int H() {
  return sqrtl(a * b) / (sqrtl(a * c) + sqrtl(b * c));
}

void Solve() {
  cin >> a >> b >> c;
  int delta = 0;
  for (; a > 0 && b > 0 && Check(); delta += H(), a -= H(), b -= H());
  cout << (a <= 0 || b <= 0 ? -1 : delta) << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  for (cin >> T; T--; Solve());
  return 0;
}