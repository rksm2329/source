#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 2e5 + 10;
const ll INF = 1e18;

int n, a[MAXN];

void chkmax(pii &ans, int k) {
  if (k >= ans.first) {
    ans.second = ans.first, ans.first = k;
  } else if (k > ans.second) ans.second = k;
}

void Solve() {
  cin >> n;
  int cnt[] = {0, 0};
  pii mx[] = {{0, 0}, {0, 0}};
  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i] & 1]++;
    chkmax(mx[a[i] & 1], a[i]);
    sum += (a[i] << 1);
  }
  ll ans = INF;
  for (int i = 1; i <= n; i++) {
    for (int _ : {0, 1}) {
      int oth = mx[_].first == a[i] ? mx[_].second : mx[_].first;
      if (!oth) continue;
      ll res = (sum - a[i] - oth) >> 1;
      cnt[a[i] & 1]--, cnt[_]--;
      int c;
      if (cnt[0] == cnt[1]) {
        c = a[i] % 2 == _ ? (max(0, 2 * cnt[0] - 1) + (cnt[0] ? 1 : 0)) : (max(0, 2 * cnt[0] - 1) + (cnt[0] ? 2 : 1));
      } else {
        bool x = cnt[0] > cnt[1] ? 0 : 1;
        if (a[i] % 2 == _ && _ != x) {
          c = 2 * cnt[x ^ 1] + 2;
        } else if (a[i] % 2 == _) {
          c = 2 * cnt[x ^ 1];
        } else if (a[i] % 2 == x) {
          c = 2 * cnt[x ^ 1];
        } else {
          c = 2 * cnt[x ^ 1] + 1;
        }
      }
      c >>= 1;
      ans = min(ans, res - c);
      cnt[a[i] & 1]++, cnt[_]++;
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  for (cin >> T; T--; Solve());
  return 0;
}