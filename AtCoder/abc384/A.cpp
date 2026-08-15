#include <bits/stdc++.h>

using namespace std;

int n;
char c1,c2;
string s;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> c1 >> c2 >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] != c1) {
      cout << c2;
    } else {
      cout << c1;
    }
  }
  return 0;
}