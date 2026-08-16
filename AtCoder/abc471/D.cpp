#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int q, v;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> q >> v;
  multiset<int> st;
  for (int i = 1, op, t; i <= q; i++) {
    cin >> op >> t;
    if (op == 1) {
      int w;
      cin >> w;
      st.insert(w - t);
    } else {
      if (st.empty()) {
        cout << "-1\n";
        continue;
      }
      cout << min(*st.rbegin() + t, v) << '\n';
      st.erase(prev(st.end()));
    }
  }
  return 0;
}