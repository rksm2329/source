#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 1e9;

int n;

int main() {
  cin >> n;
  if (n == 2) {
    cout << "! 1" << endl;
    return 0;
  }
  int ans = INF;
  for (int i = 2; i < n; i++) {
    cout << "? 1 " << i << endl;
    int l1;
    cin >> l1;
    cout << "? " << i << ' ' << n << endl;
    int l2;
    cin >> l2;
    ans = min(ans, l1 + l2);
  }
  cout << "! " << ans - 1 << endl;
  return 0;
}