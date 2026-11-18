#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10;

int n, m, cnt[MAXN];

void Solve() {
  cin >> n >> m;
  fill(cnt + 1, cnt + m + 1, 0);
  for (int i = 1, x; i <= n; i++) {
    cin >> x, cnt[x]++;
  }
  if (n % 2 || n < 2 * m) {
    cout << -1 << '\n';
    return;
  }
  int ans1 = 0, ans2, res = 0;
  for (int i = 1; i <= m; i++) {
    ans1 += cnt[i] == 1, ans2 += cnt[i] > 1 && cnt[i] % 2, res += !cnt[i];
  }
  ans2 = max(0, ans2 - ans1);
  cout << ans1 + (ans2 >= 2 * res ? ans2 / 2 + res : res * 2) << '\n';
}

int main() {
  freopen("color.in", "r", stdin);
  freopen("color.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int c, T;
  for (cin >> c >> T; T--; Solve());
  return 0;
}