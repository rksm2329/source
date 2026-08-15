#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10;

int n, a[MAXN][6];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 6; j++) {
      cin >> a[i][j];
    }
    sort(a[i], a[i] + 6);
  }
  return 0;
}