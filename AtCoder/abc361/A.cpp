#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;

int n, a[MAXN], k, x;

int main() {
  cin >> n >> k >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
    if (i == k) cout << x << ' ';
  }
  return 0;
}