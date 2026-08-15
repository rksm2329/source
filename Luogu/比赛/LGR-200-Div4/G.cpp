#include <bits/stdc++.h>

using namespace std;

int n, p, a[10];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> p;
  for (int i = 1; i <= n; i++) {
    a[i] = (i == 1);
  }
  if (n * 9 < p) {
    for (int i = 1; i <= n; i++) {
      cout << a[i];
    }
    return 0;
  }
  int sum = 1, pos = n;
  while (sum != p && a[1] != 9) {
    a[pos]++, sum++;
    if (a[pos] == 9) {
      pos--;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i];
  }
  return 0;
}