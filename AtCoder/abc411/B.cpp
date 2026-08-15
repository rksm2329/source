#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 55;

int n, a[MAXN];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int sum = 0;
      for (int k = i; k < j; k++) {
        sum += a[k];
      }
      cout << sum << ' ';
    }
    cout << '\n';
  }
  return 0;
}