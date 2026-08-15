#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string s;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> s;
  for (char i : s) {
    if (i == '2') {
      cout << i;
    }
  }
  return 0;
}