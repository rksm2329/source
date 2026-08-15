#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int fa[MAXN];
vector<int> a[MAXN];
int n, q;

int find(int x) {
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int u, int v) {
  int fu = find(u), fv = find(v);
  if (fu == fv) {
    return;
  }
  vector<int> x;
  for (int i : a[fu]) {
    x.push_back(i);
  }
  for (int i : a[fv]) {
    x.push_back(i);
  }
  sort(x.begin(), x.end(), greater<int>());
  a[fu].clear();
  a[fv].clear();
  for (int i = 0; i < min(10, int(x.size())); i++) {
    a[fv].push_back(x[i]);
  }
  fa[fu] = fv;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
    a[i].push_back(i);
  }
  for (int op, x, y; q; q--) {
    cin >> op >> x >> y;
    if (op == 1) {
      merge(x, y);
    } else {
      x = find(x);
      cout << (y > a[x].size() ? -1 : a[x][y - 1]) << '\n';
    }
  }
  return 0;
}