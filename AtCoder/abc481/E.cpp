#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using i128 = __int128;

const int MAXN = 2e5 + 10;

struct Point {
  ll x, y;
} p[MAXN];

int n;

i128 cross(const Point &a, const Point &b) {
  return (i128)a.x * b.y - (i128)a.y * b.x;
}

i128 dot(const Point &a, const Point &b) {
  return (i128)a.x * b.x + (i128)a.y * b.y;
}

int half(const Point &a) {
  return (a.y > 0 || (a.y == 0 && a.x > 0)) ? 0 : 1;
}

bool cmp(const Point &a, const Point &b) {
  int ha = half(a), hb = half(b);
  if (ha != hb) return ha < hb;
  return cross(a, b) > 0;
}

void Solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    auto &[x, y] = p[i];
    cin >> x >> y;
  }
  sort(p + 1, p + n + 1, cmp);
  vector<Point> a;
  vector<int> w;
  for (int i = 1; i <= n; i++) {
    auto v = p[i];
    if (a.empty() || cross(a.back(), v) != 0 || dot(a.back(), v) <= 0) {
      a.push_back(v);
      w.push_back(1);
    } else w.back()++;
  }
  int m = a.size();
  ll ans = 0, sum = 0;
  for (int i = 0, j = 0; i < m; i++) {
    for (; j < i + m && (j == i || cross(a[i], a[j % m]) > 0); j++) sum += w[j % m];
    ans = max(ans, sum);
    sum -= w[i];
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  for (cin >> T; T--; Solve());
  return 0;
}