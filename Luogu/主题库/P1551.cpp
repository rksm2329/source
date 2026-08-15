#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e3 + 10;

int n, m, p, x, y;
int fa[MAXN];

int find(int x) {
  if (x == fa[x]) {
    return x;
  }
  return fa[x] = find(fa[x]);
}

void add(int xx, int yy) {
  int f1 = find(xx), f2 = find(yy);
  if (f1 != f2) {
    fa[f1] = f2;
  }
}

int main() {
  cin >> n >> m >> p;
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    add(x, y);
  }
  for (int i = 1; i <= p; i++) {
    cin >> x >> y;
    cout << (find(x) == find(y) ? "Yes" : "No") << '\n';
  }
  return 0;
}