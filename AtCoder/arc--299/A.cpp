#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int x;
  cin >> x;
  if (x == 0) {
    cout << "ATCODERISTHEBESTONLINEJUDGE\n";
    return 0;
  }
  int a = 25;
  int q = x / a;
  int r = x % a;
  for (int k = 0; k < r; k++) cout << "AR";
  if (r) cout << "CR";
  for (int k = 0; k < a - r; k++) cout << "AR";
  for (int k = 0; k < q; k++) cout << "CR";
  return 0;
}