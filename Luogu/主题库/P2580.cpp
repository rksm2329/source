#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 10;

int n, m;
string name[MAXN];
map<string, int> mp;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> name[i];
    mp[name[i]] = 1;
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    string s;
    cin >> s;
    if (mp[s] == 1) {
      cout << "OK";
      mp[s] = 2;
    } else if (mp[s] == 2) {
      cout << "REPEAT";
    } else {
      cout << "WRONG";
    }
    cout << '\n';
  }
  return 0;
}