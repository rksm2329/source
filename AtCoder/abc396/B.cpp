#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int q;
stack<int> stk;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  for (int i = 1; i <= 100; i++) {
    stk.push(0);
  }
  cin >> q;
  for (int op, x; q--; ) {
    cin >> op;
    if (op == 1) {
      cin >> x;
      stk.push(x);
    } else {
      cout << stk.top() << '\n';
      stk.pop();
    }
  }
  return 0;
}