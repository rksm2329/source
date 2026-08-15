#include <bits/stdc++.h>

using namespace std;

int n, t, p, a[110];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> t >> p;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int tme = 0; ; tme++) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] >= t) {
        cnt++;
      }
    }
    if (cnt >= p) {
      cout << tme;
      return 0;
    }
    for (int i = 1; i <= n; i++) {
      a[i]++;
    }
  }
  return 0;
}