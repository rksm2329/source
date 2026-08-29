#include <bits/extc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e2 + 10, B = 91, M = 19260817;

int n, m;
string s[MAXN], t[MAXN];
vector<ll> h, p;
__gnu_pbds::gp_hash_table<int, int> cnt;

ll gethash(int l, int r) {
  return (h[r] - h[l - 1] * p[r - l + 1] % M + M) % M;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  p.assign(MAXN, 0), p[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    p[i] = p[i - 1] * B % M;
  }
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    ll hs = 0;
    for (char c : s[i]) hs = (hs * B + c) % M;
    cnt[hs]++;
  }
  for (int j = 1; j <= m; cin >> t[j++]);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    h.assign(s[i].size() + 1, 0);
    for (int j = 1; j <= s[i].size(); j++) {
      h[j] = (h[j - 1] * B + s[i][j - 1]) % M;
    }
    bool flag = 0;
    for (int j = 1; j <= m; j++) {
      if (t[j].size() > s[i].size()) continue;
      ll hs = 0;
      for (char c : t[j]) hs = (hs * B + c) % M;
      for (int k = 0; k < (int)s[i].size() - (int)t[j].size() + 1; k++) {
        if (gethash(k, k + (int)t[j].size() - 1) == hs) {
          flag = 1;
          break;
        }
      }
    }
    flag |= cnt[h[s[i].size()]] > 1;
    ans += flag;
  }
  cout << ans;
  return 0;
}