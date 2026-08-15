#include <bits/stdc++.h>

using namespace std;

string s, t;

int main() {
  cin >> s >> t;
  for (int i = 1; i < s.size(); i++) {
    for (int j = 1; j <= i; j++) {
      string u = "", v = "";
      for (int k = 0; k < s.size(); k++) {
        v += s[k];
        if ((k + 1) % i == 0) {
          u += v[j - 1];
          v = "";
        }
      }
      if (v.size() >= j) {
        u += v[j - 1];
      }
      if (u == t) {
        cout << "Yes";
        return 0;
      }
    }
  }
  cout << "No";
  return 0;
}