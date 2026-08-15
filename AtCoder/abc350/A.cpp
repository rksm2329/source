#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
  cin >> s;
  string t = s.substr(3);
  int x = 0;
  for (int i = 0; i < t.size(); i++) {
    x = x * 10 + t[i] - '0';
  }
  if (x < 350 && x != 316 && x) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  return 0;
}