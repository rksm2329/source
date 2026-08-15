#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 2e5 + 10, INF = 1e9;

struct BIT {
  int n, dat[MAXN];
  void init(int n) {
    this->n = n;
    fill(dat + 1, dat + n + 1, 0);
  }
  int get(int x) {
    int res = 0;
    for (; x; res = max(res, dat[x]), x -= x & -x);
    return res;
  }
  void upd(int x, int v) {
    for (; x <= n; dat[x] = max(dat[x], v), x += x & -x);
  }
} T;

int n, k, R[MAXN];
pii a[MAXN];

bool cmp(const pii &i, const pii &j) {
  return i.second < j.second;
}

bool check(int x) {
  T.init(n);
  for (int i = 1; i <= n; i++) {
    auto &[l, r] = a[i];
    int pos = upper_bound(R + 1, R + n + 1, l - x) - R - 1;
    T.upd(i, T.get(pos) + 1);
  }
  return T.get(n) >= k;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    R[i] = a[i].second;
  }
  int l = 0, r = INF;
  while (l < r) {
    int mid = l + r + 1 >> 1;
    check(mid) ? l = mid : r = mid - 1;
  }
  cout << (!l ? -1 : l);
  return 0;
}