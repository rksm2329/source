#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
  cin >> s;
  int p = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '.') {
      p = i;
      break;
    }
  }
  cout << s.substr(0, p);
  bool f = 1;
  for (int i = p + 1; i < s.size(); i++) {
    if (s[i] != '0') {
      f = 0;
      break;
    }
  }
  if (!f) {
    string t = "";
    bool f2 = 0;
    for (int i = s.size() - 1; i > p; i--) {
      if (s[i] != '0' || (s[i] == '0' && f2)) {
        f2 = 1;
        t += s[i];
      }
    }
    reverse(t.begin(), t.end());
    cout << '.' << t;
  }
  return 0;
}