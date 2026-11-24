#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 5e3 + 10;
const ll INF = 4e18;

int n, m, a[MAXN], b[MAXN];
ll dp[MAXN][MAXN], mi[MAXN];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; cin >> a[i++]);
  for (int i = 1; i <= m; cin >> b[i++]);
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  fill(mi + 1, mi + m + 1, INF);
  for (int i = 1; i <= n; i++) {
    for (int j = m; j; j--) {
      dp[i][j] = mi[j - 1] + abs(a[i] - b[j]);
      mi[j] = min(mi[j], dp[i][j]);
    }
  }
  cout << mi[m];
  return 0;
}