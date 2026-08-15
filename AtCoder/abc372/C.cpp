#include <bits/stdc++.h>

using namespace std;

int n, q;
string s;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> q >> s;
  int ans = 0;
  s = '#' + s;
  for (int i = 1; i <= n - 2; i++) {
    if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
      ans++;
    }
  }
  while (q--) {
    int x;
    char c;
    cin >> x >> c;
    if (x <= n - 2 && s[x] == 'A' && s[x + 1] == 'B' && s[x + 2] == 'C' && c != 'A') {
      ans--;
    } else if (x <= n - 1 && x >= 2 && s[x - 1] == 'A' && s[x] == 'B' && s[x + 1] == 'C' && c != 'B') {
      ans--;
    } else if (x <= n && x >= 3 && s[x - 2] == 'A' && s[x - 1] == 'B' && s[x] == 'C' && c != 'C') {
      ans--;
    }
    if (s[x] != c) {
      s[x] = c;
      if (x <= n - 2 && s[x] == 'A' && s[x + 1] == 'B' && s[x + 2] == 'C') {
        ans++;
      } else if (x <= n - 1 && x >= 2 && s[x - 1] == 'A' && s[x] == 'B' && s[x + 1] == 'C') {
        ans++;
      } else if (x <= n && x >= 3 && s[x - 2] == 'A' && s[x - 1] == 'B' && s[x] == 'C') {
        ans++;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}