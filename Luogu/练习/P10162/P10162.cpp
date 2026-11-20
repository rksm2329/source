#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ui32 = unsigned int;

const int MAXN = 1e6 + 10, INF = 2e9;

int n, a[MAXN], L[MAXN], R[MAXN], P[MAXN], lp[MAXN], rp[MAXN];

ui32 solve(int l, int r) {
  if (l >= r) return 0;
  int mid = l + r >> 1, mx = -INF;
  vector<int> vl, vr;
  for (int i = mid; i >= l; i--) {
    lp[i] = max(mx, L[i]);
    mx = max(mx, P[i]);
  }
  mx = -INF;
  for (int i = mid + 1; i <= r; i++) {
    rp[i] = max(mx, R[i]);
    mx = max(mx, P[i]);
  }
  sort(lp + l, lp + mid + 1);
  sort(rp + mid + 1, rp + r + 1);
  i64 sum = 0, tot = 0;
  for (int i = mid + 1; i <= r; sum += rp[i++]);
  ui32 res = 0;
  for (int i = l, cur = mid + 1; i <= mid; i++) {
    for (; cur <= r && rp[cur] <= lp[i]; tot += rp[cur++]);
    res += ui32(1ll * lp[i] * (cur - mid - 1) + sum - tot);
  }
  return res + solve(l, mid) + solve(mid + 1, r);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; cin >> a[i++]);
  for (int i = 1; i <= n; i++) {
    L[i] = i < n ? a[i] - a[i + 1] : -INF;
    R[i] = i > 1 ? a[i] - a[i - 1] : -INF;
    P[i] = min(L[i], R[i]);
  }
  cout << solve(1, n);
  return 0;
}