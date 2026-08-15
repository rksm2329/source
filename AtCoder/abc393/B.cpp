#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string s;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> s;
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    for (int j = i + 1; j < s.size(); j++) {
      for (int k = j + 1; k < s.size(); k++) {
        ans += s[i] == 'A' && s[j] == 'B' && s[k] == 'C' && j - i == k - j;
      }
    }
  }
  cout << ans;
  return 0;
}