#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 5e5 + 10;

struct BIT {
  int n, dat[MAXN];
  void init(int n) { this->n = n; }
  int get(int x) {
    int res = 0;
    for (; x; res += dat[x], x -= x & -x);
    return res;
  }
  void add(int x, int v) {
    for (; x <= n; dat[x] += v, x += x & -x);
  }
} T;

int n, pos[MAXN];
pii a[MAXN];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1, x; i <= n << 1; i++) {
    cin >> x;
    auto &[l, r] = a[x];
    !l ? l = i : r = i;
  }
  T.init(n << 1);
  for (int i = 1; i <= n << 1; T.add(i, 1), i++);
  sort(a + 1, a + n + 1, [](const pii &i, const pii &j) { return i.second - i.first < j.second - j.first; });
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    auto &[l, r] = a[i];
    int dis = T.get(r) - T.get(l - 1) - 2;
    ans += dis + 1;
    T.add(l, -1), T.add(r, -1);
  }
  cout << ans;
  return 0;
}