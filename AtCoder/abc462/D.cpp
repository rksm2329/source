#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 2e5 + 10, V = 1e6;

struct SegTree {
  ll n, dat[(V + 5) << 2];
  ll comb(const ll dat1, const ll dat2) {
    return dat1 + dat2;
  }
  void update(int root, int l, int r, int pos, int val) {
    if (l == r) {
      dat[root] += val;
      return;
    }
    int mid = l + r >> 1;
    if (pos <= mid) update(root << 1, l, mid, pos, val);
    else update(root << 1 | 1, mid + 1, r, pos, val);
    dat[root] = comb(dat[root << 1], dat[root << 1 | 1]);
  }
  ll query(int root, int l, int r, int L, int R) {
    if (L > R) return 0;
    if (L <= l && R >= r) return dat[root];
    if (L > r || R < l) return 0;
    int mid = l + r >> 1;
    return comb(query(root << 1, l, mid, L, R), query(root << 1 | 1, mid + 1, r, L, R));
  }
} T1, T2;

ll n, d;
pii a[MAXN];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> d;
  for (int i = 1; i <= n; i++) {
    auto &[l, r] = a[i];
    cin >> l >> r;
  }
  sort(a + 1, a + n + 1);
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    auto &[l, r] = a[i];
    if (r - l < d) continue;
    ans += T1.query(1, 1, V, l + d, r) - T2.query(1, 1, V, l + d, r) * (l + d - 1);
    ans += T2.query(1, 1, V, r + 1, V) * (r - l - d + 1);
    T1.update(1, 1, V, r, r), T2.update(1, 1, V, r, 1);
  }
  cout << ans;
  return 0;
}
