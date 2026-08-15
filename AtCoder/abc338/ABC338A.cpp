#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int i;
  for (i = 1; i < s.size(); i++) {
    if (s[i] < 'a') {
      break;
    }
  }
  if (i != s.size()) {
    cout << "No";
  } else {
    cout << (s[0] >= 'A' && s[0] <= 'Z' ? "Yes" : "No");
  }
  return 0;
}