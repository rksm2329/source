#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e6 + 10;

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

int n, last[MAXN];

int main() {
  freopen("happy.in", "r", stdin);
  freopen("happy.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  n <<= 1;
  T.init(n);
  for (int i = 1; i <= n; T.add(i++, 1));
  ll ans = 0;
  for (int i = 1, x; i <= n; i++) {
    cin >> x;
    if (last[x]) {
      ans += T.get(i - 1) - T.get(last[x]) + 1;
      T.add(last[x], -1), T.add(i, -1);
    } else last[x] = i;
  }
  cout << ans;
  return 0;
}