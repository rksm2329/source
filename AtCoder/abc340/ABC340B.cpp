#include <bits/stdc++.h>

using namespace std;

int q, a[110], cnt;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> q;
  for (int op, x; q--; ) {
    cin >> op >> x;
    if (op == 1) {
      a[++cnt] = x;
    } else {
      cout << a[cnt - x + 1] << '\n';
    }
  }
  return 0;
}