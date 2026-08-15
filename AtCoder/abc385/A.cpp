#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int a[3];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);
  if (a[0] == a[1] && a[1] == a[2] || a[0] + a[1] == a[2]) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  return 0;
}