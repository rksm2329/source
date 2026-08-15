#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e2 + 10;

int n, s, a[MAXN];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> s;
  bool f = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    f &= a[i] - a[i - 1] <= s;
  }
  cout << (f ? "Yes" : "No");
  return 0;
}