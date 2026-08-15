#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
  cin >> s;
  for (int i = 1; i < s.size() - 1; i++) {
    if (s[i] != '=') {
      cout << "No";
      return 0;
    }
  }
  if (s[0] == '<' && s.back() == '>') {
    cout << "Yes";
  } else {
    cout << "No";
  }
  return 0;
}