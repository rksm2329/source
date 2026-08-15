#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll ve, vm, vt, e, m, t;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> ve >> vm >> vt >> e >> m >> t;
  cout << ((e * ve + m * vm + vt - 1) / vt + t - 1) / t;
  return 0;
}