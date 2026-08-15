#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

#define int long long

string s;
map<char, int> mp, mp2;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    mp[s[i]]++;
  }
  long long ans = 0;
  for (int i = 0; i < s.size(); i++) {
    mp2[s[i]]++;
    int x = mp[s[i]] - mp2[s[i]];
    ans += (s.size() - i - 1) - x;
  }
  cout << max(ans, 1ll);
  return 0;
}