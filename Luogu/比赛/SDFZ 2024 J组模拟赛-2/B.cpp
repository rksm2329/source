#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, q;
map<string, bool> mp;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    mp[s] = 1;
  }
  for (string x; q; q--) {
    cin >> x;
    int p = x.size();
    x = '#' + x;
    bool f = 0;
    for (int i = 1; i <= p; i++) {
      string t = x.substr(1, i - 1) + x.substr(i + 1);
      if (mp.find(t) != mp.end()) {
        cout << t << '\n';
        f = 1;
        break;
      }
    }
    for (int i = 1; i <= p; i++) {
      for (char j = 'a'; j <= 'z'; j++) {
        string t = x.substr(1, i - 1) + j + x.substr(i);
        if (mp.find(t) != mp.end() && !f) {
          cout << t << '\n';
          f = 1;
          break;
        }
      }
    }
    for (int i = 1; i <= p; i++) {
      for (char j = 'a'; j <= 'z'; j++) {
        string t = x.substr(1, i - 1) + j + x.substr(i + 1);
        if (mp.find(t) != mp.end() && !f) {
          cout << t << '\n';
          f = 1;
          break;
        }
      }
    }
    if (!f) {
      cout << "No\n";
    }
  }
  return 0;
}