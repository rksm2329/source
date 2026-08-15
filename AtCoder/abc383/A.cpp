#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, b[110];
pair<int, int> a[110];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
    b[a[i].first] = a[i].second;
  }
  int q = 0;
  for (int i = 1; i <= a[n].first; i++) {
    if (q) {
      q--;
    }
    q += b[i];
  }
  cout << q;
  return 0;
}