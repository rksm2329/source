#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e2 + 10;

int n, a[MAXN];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int l = unique(a + 1, a + n + 1) - a - 1;
  cout << l << '\n';
  for (int i = 1; i <= l; i++) {
    cout << a[i] << ' ';
  }
  return 0;
}