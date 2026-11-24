#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;

int n, q, p[MAXN], fa[MAXN];

int find(int x) {
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int u, int v) {
  u = find(u), v = find(v);
  if (u != v) fa[u] = v;
}

int main() {
  freopen("automata.in", "r", stdin);
  freopen("automata.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> q;
  for (int i = 1; i <= n; cin >> p[i++]);
  for (int i = 2; i < n; i++) {
    vector<pair<int, int>> v = {{p[i - 1], i - 1}, {p[i], i}, {p[i + 1], i + 1}};
    sort(v.begin(), v.end());
    merge(i, v[0].second), merge(i, v[2].second);
  }
  for (int i = 1, k; i <= q; i++) {
    cin >> k;
    int f = 0;
    bool ok = 1;
    for (int j = 1, x; j <= k; j++) {
      cin >> x;
      if (!f) f = find(x);
      if (find(x) != f) ok = 0;
    }
    cout << ok;
  }
  return 0;
}