#include <bits/stdc++.h>

using namespace std;

int t, d, t1, d1, t2, d2;

int main() {
  cin >> t >> d >> t1 >> d1 >> t2 >> d2;
  if (t1 > t2) {
    swap(t1, t2);
    swap(d1, d2);
  }
  if (d <= d1) {
    cout << max(0, t1 - t);
  } else if (d <= d2) {
    cout << max(0, t2 - t);
  } else {
    cout << -1;
  }
  return 0;
}