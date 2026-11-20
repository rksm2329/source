#include <bits/stdc++.h>
#define mid (l + r >> 1)
#define calc(val, cnt, now) (((val) + (cnt) * (now) % MOD) % MOD)

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const int N = 5e4 + 10, P = 2e7 + 10, MOD = 1e9 + 7;

struct Node {
  int ls, rs;
  ll v, c;
} pool[P];

int n, m, top, root[N];
pll a[N];

void update(int &cur, int l, int r, int pos, int val, int cnt) {
  if (!cur) cur = ++top;
  (pool[cur].v += val) %= MOD;
  (pool[cur].c += cnt) %= MOD;
  if (l == r) return;
  if (pos <= mid) update(pool[cur].ls, l, mid, pos, val, cnt);
  else update(pool[cur].rs, mid + 1, r, pos, val, cnt);
}

pll query(vector<int> cur, vector<int> ver, int l, int r, int L, int R) {
  if (L > R) return {0, 0};
  if (L <= l && R >= r) {
    ll val = 0, cnt = 0;
    for (int crs : cur) {
      (val += pool[crs].v) %= MOD;
      (cnt += pool[crs].c) %= MOD;
    }
    for (int vrs : ver) {
      (val += MOD - pool[vrs].v) %= MOD;
      (cnt += MOD - pool[vrs].c) %= MOD;
    }
    return {val, cnt};
  }
  ll val = 0, cnt = 0;
  if (L <= mid) {
    vector<int> ncur = cur, nver = ver;
    for (int &crs : ncur) crs = pool[crs].ls;
    for (int &vrs : nver) vrs = pool[vrs].ls;
    auto [v, c] = query(ncur, nver, l, mid, L, R);
    (val += v) %= MOD, (cnt += c) %= MOD;
  }
  if (R > mid) {
    vector<int> ncur = cur, nver = ver;
    for (int &crs : ncur) crs = pool[crs].rs;
    for (int &vrs : nver) vrs = pool[vrs].rs;
    auto [v, c] = query(ncur, nver, mid + 1, r, L, R);
    (val += v) %= MOD, (cnt += c) %= MOD;
  }
  return {val, cnt};
}

void add(int x, int cur, int val, int cnt) {
  for (; x <= n; x += x & -x) {
    update(root[x], 1, n, cur, val, cnt);
  }
}

pll get(int l, int r, int L, int R) {
  if (l > r) return {0, 0};
  vector<int> cur, ver;
  for (int i = r; i; i -= i & -i) cur.push_back(root[i]);
  for (int i = l - 1; i; i -= i & -i) ver.push_back(root[i]);
  return query(cur, ver, 1, n, L, R);
}

void add(ll &ans, ll now) {
  (ans += now + MOD) %= MOD;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    auto &[x, v] = a[i];
    cin >> x >> v;
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    auto &[x, v] = a[i];
    auto [val, cnt] = get(1, i - 1, x + 1, n);
    (ans += calc(val, cnt, v)) %= MOD;
    add(i, x, v, 1);
  }
  for (int i = 1, x, y; i <= m; i++) {
    cin >> x >> y;
    if (x > y) swap(x, y);
    auto [v1, c1] = get(x, y, a[x].first + 1, n);
    auto [v2, c2] = get(x, y, 1, a[x].first - 1);
    auto [v3, c3] = get(x + 1, y, 1, a[y].first - 1);
    auto [v4, c4] = get(x + 1, y, a[y].first + 1, n);
    add(ans, calc(v1, c1, a[x].second) - calc(v2, c2, a[x].second));
    add(ans, calc(v3, c3, a[y].second) - calc(v4, c4, a[y].second));
    add(x, a[x].first, -a[x].second, -1);
    add(y, a[y].first, -a[y].second, -1);
    add(x, a[y].first, a[y].second, 1);
    add(y, a[x].first, a[x].second, 1);
    swap(a[x], a[y]);
    cout << ans << '\n';
  }
  return 0;
}