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
  for (int i = 1; i <= n - 2; i++) {
    if (a[i] == a[i + 1] && a[i + 1] == a[i + 2]) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
  return 0;
}