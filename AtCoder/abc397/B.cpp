#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string s;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> s;
  int ans = 0, k = 1;
  for (int i = 0; i < s.size(); i++, k ^= 1) {
    if (k && s[i] == 'o' || !k && s[i] == 'i') {
      ans++, k ^= 1;
    }
  }
  cout << ans + !k;
  return 0;
}