#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10;

struct BIT {
  int n, dat[MAXN];
  void init(int n) { this->n = n; }
  int get(int x) {
    int res = 0;
    for (; x; x -= x & -x) res = max(res, dat[x]);
    return res;
  }
  void update(int x, int v) {
    for (; x <= n; x += x & -x) dat[x] = max(dat[x], v);
  }
  void clear(int x) {
    for (; x <= n; x += x & -x) dat[x] = 0;
  }
} T;

struct Node {
  int id, ori, mx, mi, ans;
  bool operator<(const Node &oth) const {
    return id < oth.id;
  }
} a[MAXN];

int n, m;

/*
r.mi >= l.ori
r.ori >= l.mx
*/

bool cmp1(const Node &i, const Node &j) {
  return i.ori < j.ori;
}

bool cmp2(const Node &i, const Node &j) {
  return i.mi < j.mi;
}

void cdq(int l, int r) {
  if (l == r) return;
  int mid = l + r >> 1;
  cdq(l, mid);
  sort(a + l, a + mid + 1, cmp1);
  sort(a + mid + 1, a + r + 1, cmp2);
  int cur = l;
  for (int i = mid + 1; i <= r; i++) {
    for (; cur <= mid && a[cur].ori <= a[i].mi; cur++) {
      T.update(a[cur].mx, a[cur].ans);
    }
    a[i].ans = max(a[i].ans, T.get(a[i].ori) + 1);
  }
  for (int i = l; i < cur; i++) T.clear(a[i].mx);
  sort(a + l, a + r + 1);
  cdq(mid + 1, r);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].ori;
    a[i].id = i, a[i].mx = a[i].mi = a[i].ori;
    a[i].ans = 1;
  }
  for (int i = 1, id, val; i <= m; i++) {
    cin >> id >> val;
    a[id].mx = max(a[id].mx, val);
    a[id].mi = min(a[id].mi, val);
  }
  T.init(MAXN - 1);
  cdq(1, n);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, a[i].ans);
  }
  cout << ans;
  return 0;
}