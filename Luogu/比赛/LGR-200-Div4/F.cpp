#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e3 + 10;

string s;
int cnt[MAXN][26];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> s;
  int n = s.size();
  s = '#' + s;
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < 26; j++) {
      cnt[i][j] = cnt[i + 1][j] + (s[i] == j + 'a');
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += cnt[i][s[i] - 'a'];
  }
  cout << ans;
  return 0;
}