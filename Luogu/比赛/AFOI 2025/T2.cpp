#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 1e9, MAXN = 510;

int n;

int main() {
  cin >> n;
  for (int i = 2; i < n; i++) {
    cout << "? " << i << ' ' << n << endl;
    int x;
    cin >> x;
    if (x == 1) {
      cout << "? " << 1 << ' ' << i << endl;
      int ans;
      cin >> ans;
      cout << "! " << ans << endl;
      return 0;
    }
  }
  cout << "! 1" << endl;
  return 0;
}