#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

long long ok, len, k, x, now, ans, id, a[MAXN], flag, s[MAXN], n, sum, last;
map<long long, long long> mp;
vector<int> v[MAXN];

int main() {
  cin >> k;
  for (int i = 1; i <= k; i++) {
    cin >> len;
    for (int j = 1; j <= len; j++) cin >> x, v[i].push_back(x);
    cin >> s[i];
  }
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= k; i++) {
    flag = 1;
    for (int j = 0; j < v[i].size(); j++) {
      if (flag == 1) flag = 0, last = a[v[i][j]];
      else if (flag == 0 && last != a[v[i][j]]) flag = -1;
    }
    if (flag == 1) {
      sum += s[i];
    } else if (flag == 0) {
      mp[last] += s[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    now = mp[a[i]] + sum;
    if (now >= ans) ans = now, id = a[i];
  }
  cout << ans << '\n' << id;
  return 0;
}