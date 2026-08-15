#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;

ll n, m, sx, sy, ans;
map<ll, set<ll>> vx, vy;

void Cx(ll sx, ll ex, ll y) {
  if (!vy.count(y)) {
    return;
  }
  auto it = vy[y].lower_bound(sx);
  for (; it != vy[y].end() && *it <= ex; it = vy[y].lower_bound(sx), ans++) {
    vy[y].erase(*it), vx[*it].erase(y);
  }
}

void Cy(ll x, ll sy, ll ey) {
  if (!vx.count(x)) {
    return;
  }
  auto it = vx[x].lower_bound(sy);
  for (; it != vx[x].end() && *it <= ey; it = vx[x].lower_bound(sy), ans++) {
    vx[x].erase(*it), vy[*it].erase(x);
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> sx >> sy;
  for (int i = 1, x, y; i <= n; i++) {
    cin >> x >> y;
    vx[x].insert(y), vy[y].insert(x);
  }
  for (int i = 1, c; i <= m; i++) {
    char d;
    cin >> d >> c;
    if (d == 'U') {
      Cy(sx, sy, sy + c);
      sy += c;
    } else if (d == 'D') {
      Cy(sx, sy - c, sy);
      sy -= c;
    } else if (d == 'L') {
      Cx(sx - c, sx, sy);
      sx -= c;
    } else {
      Cx(sx, sx + c, sy);
      sx += c;
    }
  }
  cout << sx << ' ' << sy << ' ' << ans;
  return 0;
}