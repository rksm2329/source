#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e6 + 10, INF = 1e9;

string s;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> s;
  int n = s.size();
  s = '#' + s;
  int tot = 0, ans = 0, mi = INF, cnt = 0;
  for (int i = 3; i <= n; i++) {
    tot += s[i - 2] == 'A' && s[i - 1] == 'B' && s[i] == 'C';
  }
  for (int i = 1; i <= n; i++) {
    if (i >= 3) {
      if (s[i - 2] == 'A' && s[i - 1] == 'B' && s[i] == 'C') cnt++;
      if (s[i - 2] == 'C' && s[i - 1] == 'B' && s[i] == 'A') cnt--;
    }
    ans = max(ans, cnt - mi);
    mi = min(mi, cnt);
  }
  cout << tot - ans;
  return 0;
}