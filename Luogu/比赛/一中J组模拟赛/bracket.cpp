#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e6 + 10;

int n, q, top, a[MAXN], tot;
ll ans;
string s;

void dfs(int x, string &k) {
  if (x == n + 1) {
    if (tot % 2) {
      return;
    }
    top = 0;
    for (int i = 0; i < k.size(); i++) {
      if (k[i] == '(') {
        top++;
      } else {
        top--;
        if (top < 0) {
          return;
        }
      }
    }
    if (top) {
      return;
    }
    for (int i = 0; i < k.size(); i++) {
      if (i && s[i] == s[i - 1]) {
        return;
      }
    }
    ll sum = 0;
    for (int i = 1; i <= tot; i++) {
      if (k[i - 1] == ')') {
        sum += a[i];
      } else {
        sum -= a[i];
      }
    }
    ans = max(ans, sum);
    return;
  }
  dfs(x + 1, k);
  a[++tot] = x;
  string t = k;
  t += s[x];
  dfs(x + 1, t);
  tot--;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  //freopen("bracket.in", "r", stdin);
  //freopen("bracket.out", "w", stdout);
  cin >> n >> q >> s;
  s = '#' + s;
  for (int x; q--; ) {
    cin >> x;
    char c;
    cin >> c;
    s[x] = c;
    ans = 0;
    tot = 0;
    string t = "";
    dfs(1, t);
    cout << ans << '\n';
  }
  return 0;
}