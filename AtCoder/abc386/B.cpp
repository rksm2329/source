#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string s;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> s;
  int ans = 0, len = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != '0') {
      ans++;
      ans += len / 2 + len % 2;
      len = 0;
    } else {
      len++;
    }
  }
  cout << ans + len / 2 + len % 2;
  return 0;
}