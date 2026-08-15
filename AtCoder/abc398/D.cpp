#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;

int n, r, c, a[MAXN][2];
string s;
map<pair<int, int>, int> m;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> r >> c >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'N') {
      a[i + 1][0] = -1;
    } else if (s[i] == 'W') {
      a[i + 1][1] = -1;
    } else if (s[i] == 'S') {
      a[i + 1][0] = 1;
    } else {
      a[i + 1][1] = 1;
    }
  }
  m[{0, 0}] = 1;
  for (int i = 1, sum1 = 0, sum2 = 0; i <= n; m[{sum1, sum2}] = 1, i++) {
    sum1 += a[i][0], sum2 += a[i][1];
    cout << (m.find({sum1 - r, sum2 - c}) != m.end());
  }
  return 0;
}