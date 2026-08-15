#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const int MAXL = 62, MOD = 998244353;

ll t, n, k;
pll dp[MAXL][MAXL];

pll F(vector<int> &num, int pos, int cnt, bool limit) {
  if (pos < 0) {
    return {0, cnt == k};
  }
  if (!limit && dp[pos][cnt].second != -1) {
    return dp[pos][cnt];
  }
  pll res = {0, 0};
  int r = limit ? num[pos] : 1;
  for (int i = 0; i <= r; i++) {
    pll p = F(num, pos - 1, cnt + i, limit & (i == r));
    (res.first += p.first) %= MOD, (res.second += p.second) %= MOD;
    if (i) (res.first += (1ll << pos) % MOD * p.second % MOD) %= MOD;
  }
  if (!limit) dp[pos][cnt] = res;
  return res;
}

void Solve() {
  cin >> n >> k;
  vector<int> num;
  for (; n; num.push_back(n & 1), n >>= 1);
  memset(dp, -1, sizeof(dp));
  cout << F(num, num.size() - 1, 0, 1).first << '\n';
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  for (cin >> t; t--; Solve());
  return 0;
}