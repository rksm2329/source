#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int k;
string s, t;

bool C1(string s, string t) {
  if (s == t) {
    return 1;
  }
  if (s.size() == t.size()) {
    return 0;
  }
  if (s.size() > t.size()) {
    swap(s, t);
  }
  int n = s.size(), m = t.size();
  s = '#' + s, t = '#' + t;
  int cnt = 0;
  for (int i = 1, j = 1; i <= n || j <= m; i++, j++) {
    if (s[i] != t[j]) {
      j++;
      cnt++;
    }
    if (cnt > 1) {
      return 0;
    }
  }
  return 1;
}

bool C2(string s, string t) {
  if (s == t) {
    return 1;
  }
  if (s.size() != t.size()) {
    return 0;
  }
  int n = s.size(), m = t.size();
  s = '#' + s, t = '#' + t;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cnt += s[i] != t[i];
  }
  return cnt <= 1;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> k >> s >> t;
  if (abs(int(s.size()) - int(t.size())) > 1) {
    cout << "No";
    return 0;
  }
  cout << (C1(s, t) || C2(s, t) ? "Yes" : "No");
  return 0;
}