#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  cin >> n;
  int cnt = 0;
  bool f = 0;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    if (s == "sweet") {
      cnt++;
    } else {
      cnt = 0;
    }
    if (cnt == 2 && i != n) {
      f = 1;
    }
  }
  cout << (f ? "No" : "Yes");
  return 0;
}