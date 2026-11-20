#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10;

struct BIT {
  int n, dat[MAXN];
  void init(int n) { this->n = n; }
  int get(int x) {
    if (x <= 0) return 0;
    if (x > n) x = n;
    int res = 0;
    for (; x; res += dat[x], x -= x & -x);
    return res;
  }
  void add(int x, int v) {
    for (; x <= n; dat[x] += v, x += x & -x);
  }
} T;

struct Node {
  int x, y, val;
} a[MAXN];

int n, k;
ll ans;

bool cmp1(const Node &i, const Node &j) {
  return i.x < j.x;
}

bool cmp2(const Node &i, const Node &j) {
  return i.y > j.y;
}

void cdq(int l, int r) {
  if (l == r) return;
  int mid = l + r >> 1;
  cdq(l, mid), cdq(mid + 1, r);
  sort(a + l, a + mid + 1, cmp2);
  sort(a + mid + 1, a + r + 1, cmp2);
  int cur = l;
  for (int i = mid + 1; i <= r; i++) {
    auto &[x, y, val] = a[i];
    while (cur <= mid && a[cur].y > y) T.add(a[cur++].val, 1);
    ans += T.get(val - k - 1) + T.get(n) - T.get(val + k);
  }
  for (int i = l; i < cur; i++) T.add(a[i].val, -1);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1, x; i <= n; i++) {
    cin >> x;
    a[x].val = x, a[x].x = i;
  }
  for (int i = 1, x; i <= n; i++) {
    cin >> x;
    a[x].y = i;
  }
  T.init(n);
  sort(a + 1, a + n + 1, cmp1);
  cdq(1, n);
  cout << ans;
  return 0;
}