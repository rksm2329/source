#include <bits/stdc++.h>

using namespace std;

string s;
map<string, bool> mp;

int main() {
  cin >> s;
  long long ans = 0;
  for (int i = 0; i < s.size(); i++) {
    for (int j = i; j < s.size(); j++) {
      if (!mp[s.substr(i, j - i + 1)]) {
        mp[s.substr(i, j - i + 1)] = 1;
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}