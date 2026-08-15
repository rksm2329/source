#include <bits/stdc++.h>

using namespace std;

string s;
int c1[26], c2[110];

int main() {
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    c1[s[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    c2[c1[i]]++;
  }
  for (int i = 1; i <= s.size(); i++) {
    if (c2[i] != 0 && c2[i] != 2) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}