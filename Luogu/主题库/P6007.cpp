#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10;
const ll INF = 1e18;

struct Point {
  int x, y, flag, id;
} val[MAXN << 1];

int n, p, m;
ll ans[MAXN];

int dist(const Point &i, const Point &j) {
  return abs(i.x - j.x) + abs(i.y - j.y);
}

bool cmp1(const Point &i, const Point &j) {
  if (i.x != j.x) return i.x < j.x;
  if (i.y != j.y) return i.y < j.y;
  return i.flag > j.flag;
}

bool cmp2(const Point &i, const Point &j) {
  if (i.y != j.y) return i.y < j.y;
  if (i.x != j.x) return i.x < j.x;
  return i.flag > j.flag;
}

void cdq(int l, int r) {
  if (l == r) return;
  int mid = l + r >> 1;
  cdq(l, mid);
  sort(val + l, val + mid + 1, cmp2);
  sort(val + mid + 1, val + r + 1, cmp2);
  ll res = INF;
  for (int i = mid + 1, cur = l; i <= r; i++) {
    if (val[i].flag) continue;
    for (; cur <= mid && val[cur].y <= val[i].y; cur++) {
      if (val[cur].flag) {
        res = min(res, ans[val[cur].id] - val[cur].x - val[cur].y);
      }
    }
    ans[val[i].id] = min(ans[val[i].id], res + val[i].x + val[i].y);
  }
  sort(val + l, val + r + 1, cmp1);
  cdq(mid + 1, r);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> p;
  for (int i = 1, x1, y1, x2, y2; i <= p; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    val[++m] = {x1, y1, 0, i};
    val[++m] = {x2, y2, 1, i};
  }
  val[++m] = {0, 0, 1, 0}, val[++m] = {n, n, 0, p + 1};
  sort(val + 1, val + m + 1, cmp1);
  fill(ans + 1, ans + p + 2, INF);
  cdq(1, m);
  cout << ans[p + 1];
  return 0;
}
