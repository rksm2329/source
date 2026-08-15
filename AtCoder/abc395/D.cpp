#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e6 + 10;

int n, q, f[MAXN], g[MAXN], p[MAXN];

void Work(int op, int x, int y) {
  cin >> op >> x;
  if (op == 1) {
    cin >> y;
    p[x] = g[y];
  } else if (op == 2) {
    cin >> y;
    f[g[x]] = y, f[g[y]] = x;
    swap(g[x], g[y]);
  } else {
    cout << f[p[x]] << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> q;
  iota(f + 1, f + n + 1, 1);
  iota(g + 1, g + n + 1, 1);
  iota(p + 1, p + n + 1, 1);
  for (int op, x, y; q--; Work(op, x, y));
  return 0;
}