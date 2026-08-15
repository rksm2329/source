#include <bits/stdc++.h>

using namespace std;

string expend() {
  string s = "", x;
  char c;
  int d;
  while (cin >> c) {
    if (c == '[') {
      cin >> d;
      x = expend();
      while (d--) s += x;
    } else if (c == ']') {
      return s;
    } else {
      s += c;
    }
  }
  return s;
}

int main() {
  cout << expend();
  return 0;
}