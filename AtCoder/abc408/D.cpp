#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;

string s;
int n, res[MAXN];

void Solve() {
  cin >> n >> s;
  s = '#' + s;
  int cnt1 = 0;
  res[n + 1] = 0;
  for (int i = n; i >= 1; i--) {
    res[i] = min(res[i + 1], cnt1) + (s[i] == '0');
    cnt1 += s[i] == '1';
  }
  int ans = n;
  cnt1 = 0;
  for (int i = 0; i <= n; i++) {
    cnt1 += s[i] == '1';
    ans = min(ans, cnt1 + res[i + 1]);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int T;
  for (cin >> T; T--; Solve());
  return 0;
}