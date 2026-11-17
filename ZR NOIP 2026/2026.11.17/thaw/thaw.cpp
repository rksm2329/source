#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;
const ll INF = 2e14;

int n, k, a[MAXN];
ll pre[MAXN], suf[MAXN];

bool check(ll x) {
  int L = 1;
  for (; L <= n && pre[L] <= x; L++);
  L--;
  int R = n;
  for (; R >= 1 && suf[R] <= x; R--);
  R++;
  int cnt = 0;
  for (int i = L + 1; i < R; i++) {
    if (pre[i] - pre[L] > x) {
      cnt++, L = upper_bound(pre + 1, pre + n + 1, x + pre[i - 2]) - pre - 1, i = L;
    }
    if (pre[i] - pre[L] <= x && pre[R - 1] - pre[i - 1] <= x) {
      cnt++;
      break;
    }
  }
  return cnt <= k;
}

int main() {
  freopen("thaw.in", "r", stdin);
  freopen("thaw.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pre[i] = pre[i - 1] + a[i];
  }
  for (int i = n; i >= 1; i--) {
    suf[i] = suf[i + 1] + a[i];
  }
  ll l = *max_element(a + 1, a + n + 1), r = INF;
  while (l < r) {
    ll mid = l + r >> 1;
    check(mid) ? r = mid : l = mid + 1;
  }
  cout << l;
  return 0;
}