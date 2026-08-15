#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;
const ll INF = 2e18;

int n, m, a[MAXN], b[MAXN];
ll mx[MAXN];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  sort(a + 1, a + n + 1, greater<int>());
  sort(b + 1, b + m + 1, greater<int>());
  ll s = b[1];
  for (int i = 1; i <= m; i++, s += b[i]) {
    mx[i] = s > mx[i - 1] ? s : mx[i - 1];
  }
  ll ans = 0, sum = a[1];
  for (int i = 1; i <= n; i++, sum += a[i]) {
    ans = max(ans, sum + mx[min(i, m)]);
  }
  cout << ans;
  return 0;
}