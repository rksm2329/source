#include <bits/stdc++.h>

using namespace std;

string s, t;

int main() {
  cin >> s >> t;
  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (char(s[i] - 32) == t[cnt]) {
      cnt++;
    }
    if (cnt == 3) {
      break;
    }
  }
  if (cnt == 3) {
    cout << "Yes";
  } else {
    if (cnt == 2) {
      if (t[2] == 'X') {
        cout << "Yes";
      } else {
        cout << "No";
      }
    } else {
      cout << "No";
    }
  }
  return 0;
}