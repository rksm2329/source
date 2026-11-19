#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10, MAXV = 1 << 14;

struct ST {
  int f[20][MAXN], arr[MAXN];
  int Max(int i, int j) {
    return arr[i] > arr[j] ? i : j;
  }
  void init(int n, int *a) {
    for (int i = 1; i <= n; i++) f[0][i] = i, arr[i] = a[i];
    for (int k = 1; k <= __lg(n); k++) {
      for (int i = 1; i + (1 << k - 1) <= n; i++) {
        f[k][i] = Max(f[k - 1][i], f[k - 1][i + (1 << k - 1)]);
      }
    }
  }
  int query(int l, int r) {
    int k = __lg(r - l + 1);
    return Max(f[k][l], f[k][r - (1 << k) + 1]);
  }
} S;

int n, a[MAXN], cnt[MAXV];
bool flag;

ll solve(int l, int r) {
  if (l >= r) return 0;
  int mid = S.query(l, r);
  ll ans = flag ? 1ll * ((mid - l + 1) * (r - mid + 1) - 1) : 0;
  if (mid - l <= r - mid) {
    for (int i = l; i <= mid; cnt[a[i++]]++);
    if (!flag) {
      for (int i = mid; i <= r; i++) {
        if (i == mid) cnt[a[mid]]--;
        if (!a[i]) {
          ans += cnt[MAXV - 1];
          for (int mask = a[i]; mask != MAXV - 1; mask = (mask + 1) | a[i]) ans += cnt[mask];
          if (i == mid) cnt[a[mid]]++;
          continue;
        }
        if (a[i] == MAXV - 1) {
          ans += cnt[0];
          for (int mask = a[i]; mask; mask = (mask - 1) & a[i]) ans += cnt[mask];
          if (i == mid) cnt[a[mid]]++;
          continue;
        }
        ans += cnt[0] + cnt[MAXV - 1];
        for (int mask = a[i]; mask; mask = (mask - 1) & a[i]) ans += cnt[mask];
        for (int mask = a[i]; mask != MAXV - 1; mask = (mask + 1) | a[i]) ans += cnt[mask];
        ans -= cnt[a[i]];
        if (i == mid) cnt[a[mid]]++;
      }
    }
    for (int i = l; i <= mid; cnt[a[i++]]--);
  } else {
    for (int i = mid; i <= r; cnt[a[i++]]++);
    if (!flag) {
      for (int i = l; i <= mid; i++) {
        if (i == mid) cnt[a[mid]]--;
        if (!a[i]) {
          ans += cnt[MAXV - 1];
          for (int mask = a[i]; mask != MAXV - 1; mask = (mask + 1) | a[i]) ans += cnt[mask];
          if (i == mid) cnt[a[mid]]++;
          continue;
        }
        if (a[i] == MAXV - 1) {
          ans += cnt[0];
          for (int mask = a[i]; mask; mask = (mask - 1) & a[i]) ans += cnt[mask];
          if (i == mid) cnt[a[mid]]++;
          continue;
        }
        ans += cnt[0] + cnt[MAXV - 1];
        for (int mask = a[i]; mask; mask = (mask - 1) & a[i]) ans += cnt[mask];
        for (int mask = a[i]; mask != MAXV - 1; mask = (mask + 1) | a[i]) ans += cnt[mask];
        ans -= cnt[a[i]];
        if (i == mid) cnt[a[mid]]++;
      }
    }
    for (int i = mid; i <= r; cnt[a[i++]]--);
  }
  return ans * a[mid] + solve(l, mid - 1) + solve(mid + 1, r);
}

int main() {
  freopen("problem.in", "r", stdin);
  freopen("problem.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; cin >> a[i++]);
  S.init(n, a);
  flag = *max_element(a + 1, a + n + 1) >= (1 << 7);
  cout << solve(1, n);
  return 0;
}