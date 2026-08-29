#include <bits/extc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;

int n, k, a[MAXN], dp[MAXN];
ll pre[MAXN];
__gnu_pbds::gp_hash_table<int, int> lst;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pre[i] = (pre[i - 1] + a[i]) % k;
  }
  lst[0] = 0;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = mx;
    if (lst.find(pre[i]) != lst.end()) dp[i] = max(dp[i], dp[lst[pre[i]]] + 1);
    mx = max(mx, dp[i]), lst[pre[i]] = i;
  }
  cout << mx;
  return 0;
}