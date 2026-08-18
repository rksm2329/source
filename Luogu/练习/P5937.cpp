#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10;

struct Query {
  int l, r;
  bool res;
} a[MAXN];

struct Lsh {
  vector<int> v;
  void Add(int x) {
    v.push_back(x);
  }
  void Build() {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()));
  }
  int Rnk(int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
  }
  int Len() {
    return v.size();
  }
} L;

struct DSU {
  int fa[MAXN], w[MAXN], n;
  void Init(int n) {
    this->n = n;
    iota(fa + 1, fa + n + 1, 1);
  }
  int Find(int x) {
    if (fa[x] == x) {
      return x;
    }
    int f = Find(fa[x]);
    w[x] ^= w[fa[x]];
    return fa[x] = f;
  }
  bool Merge(int u, int v, int d) {
    int fu = Find(u), fv = Find(v);
    if (fu == fv) return (w[u] ^ w[v]) == d;
    fa[fu] = fv, w[fu] = w[u] ^ w[v] ^ d;
    return 1;
  }
} D;

int n, m;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  if (!m) {
    cout << 0;
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    string s;
    cin >> a[i].l >> a[i].r >> s;
    L.Add(--a[i].l), L.Add(a[i].r);
    a[i].res = s == "odd";
  }
  L.Build();
  D.Init(L.Len());
  for (int i = 1; i <= m; i++) {
    a[i].l = L.Rnk(a[i].l), a[i].r = L.Rnk(a[i].r);
    if (!D.Merge(a[i].l, a[i].r, a[i].res)) {
      cout << i - 1;
      return 0;
    }
  }
  cout << m;
  return 0;
}