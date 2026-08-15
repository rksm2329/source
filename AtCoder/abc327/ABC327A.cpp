#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main() {
  cin >> n >> s;
  cout << (s.find("ab") != string::npos || s.find("ba") != string::npos ? "Yes" : "No");
  return 0;
}