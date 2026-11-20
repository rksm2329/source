#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 40, MOD = 1e9 + 7;

int h, w, m, n, mi[MAXN][MAXN], v[MAXN];
pii a[2][MAXN];

ll qpow(ll x, ll y) {
  ll res = 1;
  for (; y; y >>= 1, (x *= x) %= MOD) {
    if (y & 1) (res *= x) %= MOD;
  }
  return res;
}

void Solve() {
  cin >> h >> w >> m >> n;
  vector<int> lx, ly;
  for (int i = 0; i < n; i++) {
    for (int _ : {0, 1}) {
      auto &[x, y] = a[_][i];
      cin >> x >> y;
    }
    cin >> v[i];
    lx.push_back(a[0][i].first);
    lx.push_back(a[1][i].first + 1);
    ly.push_back(a[0][i].second);
    ly.push_back(a[1][i].second + 1);
  }
  lx.push_back(1), lx.push_back(h + 1);
  ly.push_back(1), ly.push_back(w + 1);
  sort(lx.begin(), lx.end());
  sort(ly.begin(), ly.end());
  lx.erase(unique(lx.begin(), lx.end()), lx.end());
  ly.erase(unique(ly.begin(), ly.end()), ly.end());
  ll ans = 0;
  for (int S = 0; S < 1 << n; S++) {
    fill(&mi[0][0], &mi[lx.size() - 2][ly.size() - 2] + 1, m);
    for (int i = 0; i < n; i++) {
      auto [x0, y0] = a[0][i];
      auto &[x1, y1] = a[1][i];
      x0 = lower_bound(lx.begin(), lx.end(), x0) - lx.begin();
      y0 = lower_bound(ly.begin(), ly.end(), y0) - ly.begin();
      for (int j = x0; lx[j] != x1 + 1; j++) {
        for (int k = y0; ly[k] != y1 + 1; k++) {
          mi[j][k] = min(mi[j][k], v[i] - (S >> i & 1));
        }
      }
    }
    ll res = 1;
    for (int i = 0; i < lx.size() - 1; i++) {
      for (int j = 0; j < ly.size() - 1; j++) {
        (res *= qpow(mi[i][j], (lx[i + 1] - lx[i]) * (ly[j + 1] - ly[j]))) %= MOD;
      }
    }
    (ans += __builtin_popcount(S) & 1 ? MOD - res : res) %= MOD;
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  for (cin >> T; T--; Solve());
  return 0;
}