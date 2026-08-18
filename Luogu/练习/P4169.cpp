#include <bits/stdc++.h>
#define backup(l, r) copy(a + l, a + r + 1, ori + l)
#define recover(l, r) copy(ori + l, ori + r + 1, a + l);

using namespace std;
using ll = long long;

const int MAXN = 3e5 + 10, V = 1e6 + 1, INF = 1e9;

struct BIT {
  int n, dat[V + 1];
  void init(int n) {
    this->n = n;
    fill(dat + 1, dat + n + 1, -INF);
  }
  int get(int x) {
    int res = -INF;
    for (; x; x -= x & -x) res = max(res, dat[x]);
    return res;
  }
  void add(int x, int v) {
    for (; x <= n; x += x & -x) dat[x] = max(dat[x], v);
  }
  void clear(int x) {
    for (; x <= n; x += x & -x) dat[x] = -INF;
  }
} T;

struct Node {
  int t, x, y, id;
  bool operator<(const Node &oth) const {
    return x < oth.x;
  }
} a[MAXN << 1], ori[MAXN << 1];

int n, m, ans[MAXN];

void cdq(int l, int r) {
  if (l == r) return;
  int mid = l + r >> 1;
  cdq(l, mid), cdq(mid + 1, r);
  sort(a + l, a + mid + 1);
  sort(a + mid + 1, a + r + 1);
  int cur = l;
  for (int i = mid + 1; i <= r; i++) {
    auto &[t, x, y, id] = a[i];
    for (; cur <= mid && a[cur].x <= x; cur++) {
      if (!a[cur].id) T.add(a[cur].y + 1, a[cur].x + a[cur].y);
    }
    if (id) ans[id] = min(ans[id], x + y - T.get(y + 1));
  }
  for (int i = l; i < cur; i++) {
    if (!a[i].id) T.clear(a[i].y + 1);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    auto &[t, x, y, id] = a[i];
    cin >> x >> y; t = id = 0;
  }
  int res_tot = 0;
  for (int i = 1, op; i <= m; i++) {
    auto &[t, x, y, id] = a[n + i];
    cin >> op >> x >> y; t = i;
    id = op == 1 ? 0 : ++res_tot;
  }
  fill(ans + 1, ans + res_tot + 1, INF);
  T.init(V);
  int tot = n + m; backup(1, tot);
  cdq(1, tot);
  recover(1, tot);
  for (int i = 1; i <= tot; i++) {
    a[i].x = V - a[i].x - 1;
  }
  cdq(1, tot);
  recover(1, tot);
  for (int i = 1; i <= tot; i++) {
    a[i].y = V - a[i].y - 1;
  }
  cdq(1, tot);
  recover(1, tot);
  for (int i = 1; i <= tot; i++) {
    a[i].x = V - a[i].x - 1;
    a[i].y = V - a[i].y - 1;
  }
  cdq(1, tot);
  for (int i = 1; i <= res_tot; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}