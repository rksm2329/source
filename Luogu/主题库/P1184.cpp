#include <iostream>

using namespace std;

int n, m;
string s[21], t;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    getchar();
    getline(cin, s[i]);
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    getline(cin, t);
    for (int j = 1; j <= n; j++) {
      if (s[j] == t && s[j].size() == t.size()) {
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}