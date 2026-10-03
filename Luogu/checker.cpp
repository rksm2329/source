#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int u[50], v[50], w[50];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    cin >> w[i] >> u[i] >> v[i];
  }
  vector<int> vec(n + 1);
  for (int i = 1; i <= n; cin >> vec[i++]);
  for (int i = 1; i <= q; i++) {
    if (vec[v[i]] < vec[u[i]] + w[i]) {
      cout << "Failed on test " << i;
      return 0;
    }
  }
  cout << "Succeed!";
  return 0;
}