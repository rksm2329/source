#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
string s;

void Solve() {
  cin >> n >> s;
  int l = 0, r = n - 1;
  for (int i = 1; i < n; i++) {
    bool k = s[i] < s[i - 1];
    if (k && !l) l = i;
    if (!k && l && s[i] > s[l - 1]) {
      r = i - 1;
      break;
    }
  }
  for (int i = 0; i < l - 1; i++) {
    cout << s[i];
  }
  for (int i = l; i <= r; i++) {
    cout << s[i];
  }
  if (l > 0) {
    cout << s[l - 1];
  }
  for (int i = r + 1; i < n; i++) {
    cout << s[i];
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int T;
  for (cin >> T; T--; Solve());
  return 0;
}