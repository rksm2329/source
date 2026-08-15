#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
  cin >> s;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] != '.') {
      cout << s[i];
    }
  }
  return 0;
}