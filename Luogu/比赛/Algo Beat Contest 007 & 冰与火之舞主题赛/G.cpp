#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m, k;

void Solve() {
  cin >> n >> m >> k;
  if (n > m) swap(n, m);
  cout << (n - k) * m << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  for (cin >> T; T--; Solve());
  return 0;
}