#include <bits/stdc++.h>

using namespace std;

string s;
int cnt[26];

int main() {
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    cnt[s[i] - 'a']++;
  }
  pair<int, char> ans = {INT_MIN, '#'};
  for (int i = 0; i < 26; i++) {
    if (cnt[i] > ans.first) {
      ans.first = cnt[i];
      ans.second = i + 'a';
    }
  }
  cout << ans.second;
  return 0;
}