#include <bits/stdc++.h>

using namespace std;

int n, q;
string s, w;

int main() {
  cin >> n >> q >> s >> w;
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < q; i++) {
    cnt1 += w[i] == '1';
    cnt2 += w[i] == '2';
  }
  if (cnt1 % 2) {
    reverse(s.begin(), s.end());
  }
  if (cnt2 % 2) {
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        s[i] = '0';
      } else if (s[i] == '0') {
        s[i] = '1';
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << s[i];
  }
  return 0;
}