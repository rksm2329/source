#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int a[4];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> a[0] >> a[1] >> a[2] >> a[3];
  sort(a, a + 4);
  if ((a[0] == a[1] && a[1] == a[2] && a[2] != a[3]) || (a[0] == a[1] && a[2] == a[3] && a[1] != a[2]) || (a[1] == a[2] && a[2] == a[3] && a[0] != a[1])) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  return 0;
}