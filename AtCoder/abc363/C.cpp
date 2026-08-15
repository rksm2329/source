#include <bits/stdc++.h>

using namespace std;

string s;
int n, k, a[15];

int main() {
  cin >> n >> k >> s;
  for (int i = 0; i < n; i++) {
    a[i] = i + 1;
  }
  int ans = 0;
  map<string, bool> mp;
  do {
    string t = "";
    for (int i = 0; i < n; i++) {
      t.push_back(s[a[i] - 1]);
    }
    if (mp[t]) {
      continue;
    }
    bool f = 1;
    for (int i = 0; i + k <= n; i++) {
      bool f2 = 1;
      for (int x = i, y = i + k - 1; x <= y; x++, y--) {
        if (t[x] != t[y]) {
          f2 = 0;
          break;
        }
      }
      if (f2) {
        f = 0;
        break;
      }
    }
    if (f) {
      ans++;
    }
    mp[t] = 1;
  } while (next_permutation(a, a + n));
  cout << ans;
  return 0;
}