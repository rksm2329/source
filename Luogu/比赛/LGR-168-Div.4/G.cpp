#include <bits/stdc++.h>
#include <cwchar>

using namespace std;

int n, k;
string s;
map<string, int> mp;

int main() {
  /*ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);*/
  cin >> n >> k;
  for (int i = 1, x; i <= n; i++) {
    cin >> s >> x;
    mp[s] = x;
  }
  for (int i = 1; i <= k; i++) {
    if (i == 1) {
      getchar();
    }
    getline(cin, s);
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == '{') {
        string t = "";
        for (j++; j < s.size() && s[j] != '}'; j++) {
          t += s[j];
        }
        cout << mp[t];
      } else {
        cout << s[j];
      }
    }
    cout << '\n';
  }
  return 0;
}