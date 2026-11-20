#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string s;

void Solve() {
  cin >> s;
  reverse(s.begin(), s.end());
  bool flag = 0;
  for (char &c : s) {
    if (c < '9') {
      c++, flag = 1;
      break;
    }
  }
  if (!flag) s += '1';
  reverse(s.begin(), s.end());
  cout << s << '\n';
}

int main() {
  freopen("lucky.in", "r", stdin);
  freopen("lucky.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int T;
  for (cin >> T; T--; Solve());
  return 0;
}