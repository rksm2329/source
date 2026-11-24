#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 5e5 + 10;

int n, pos[26], last[MAXN], from[MAXN], to[MAXN];
string s;
vector<int> node;

int main() {
  freopen("glyph.in", "r", stdin);
  freopen("glyph.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> s;
  s = '#' + s;
  for (int i = 1; i <= n; i++) pos[s[i] - 'a'] = i;
  int mip = 0, ch = 26;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < s[i] - 'a'; j++) {
      if (pos[j] > i) {
        ch = j;
        break;
      }
    }
    if (ch != 26) {
      mip = i;
      break;
    }
  }
  fill(last, last + 26, pos[ch]);
  for (int i = pos[ch] - 1; i >= mip; i--) {
    int lst = pos[ch];
    for (int j = s[i] - 'a'; j < 26; j++) {
      lst = min(lst, last[j]);
    }
    from[i] = lst, last[s[i] - 'a'] = i;
  }
  for (int u = mip; u != pos[ch]; u = from[u]) node.push_back(u);
  node.push_back(pos[ch]);
  int m = node.size();
  iota(to + 1, to + n + 1, 1);
  for (int i = 0; i < m; i++) {
    to[node[i]] = node[(i + m - 1) % m];
  }
  for (int i = 1; i <= n; i++) cout << s[to[i]];
  return 0;
}