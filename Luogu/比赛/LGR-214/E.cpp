#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 5e3 + 10;

int n, k, a[MAXN], b[MAXN];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  int ans = 0;
  for (int i = 1; i <= n - k + 1; i++) {
    for (int j = 1; j <= n; j++) {
      a[j] = b[j];
    }
    for (int j = i; j <= i + k - 1; j++) {
      a[j] -= 2;
    }
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      if (a[j] < 99 - a[j]) {
        cnt++;
      }
    }
    if (cnt > (n >> 1)) {
      ans++;
    }
  }
  cout << ans;
  return 0;
}