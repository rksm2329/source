#include <bits/stdc++.h>

using namespace std;
using i128 = __int128;
using i64 = long long;
using ui64 = unsigned long long;

const int MAXN = 2e6 + 10;

int n, a[MAXN], cnt[MAXN], ver[MAXN];
vector<int> len[MAXN];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; cin >> a[i++]);
  if (n <= 5000) {
    ui64 ans = 0;
    for (int l = 1; l <= n; l++) {
      i64 mex = 0, vor = 0;
      fill(cnt, cnt + n + 1, 0);
      for (int r = l; r <= n; r++) {
        vor |= a[r];
        if (a[r] <= n) cnt[a[r]]++;
        for (; cnt[mex]; mex++);
        ans += vor | mex;
      }
    }
    cout << ans;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 30; j++) {
      if (a[i] >> j & 1) continue;
      if (len[j].empty() || i == 1 || (a[i - 1] >> j & 1)) len[j].push_back(0);
      len[j].back()++;
    }
  }
  ui64 ans = 0;
  int cur = 1;
  for (int i = 0; i < 30; i++) {
    i64 now = 1ll * n * (n + 1) >> 1, V = 1ll << i;
    for (int x : len[i]) now -= 1ll * x * (x + 1) >> 1;
    ans += (i128)now * V;
    i64 res = 0, st = 1, tot = 0;
    if (V > n) continue;
    for (int L = 1, R = 1; R <= n; R++) {
      if (a[R] >> i & 1) {
        cur++, tot = 0;
        L = R + 1, st = R + 1;
        continue;
      }
      if (a[R] < V) {
        if (ver[a[R]] != cur) cnt[a[R]] = 0, ver[a[R]] = cur;
        tot += !cnt[a[R]]++;
      }
      for (; tot == V; L++) tot -= a[L] < V && ver[a[L]] == cur && !--cnt[a[L]];
      res += L - st;
    }
    ans += (i128)res * V, cur++;
  }
  cout << ans;
  return 0;
}