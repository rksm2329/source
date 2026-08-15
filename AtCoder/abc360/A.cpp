#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
  cin >> s;
  int x = s.find('R');
  int y = s.find('M');
  cout << (x < y ? "Yes" : "No");
  return 0;
}