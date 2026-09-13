#include <bits/stdc++.h>
#define COMB(cur) pool[cur].assign(comb(pool[pool[cur].ls], pool[pool[cur].rs]))

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 2e4 + 10, P = 1e6 + 10, INF = 1e9;

struct Node {
  int ls, rs;
  ll v, lv, rv;
  void assign(const Node &oth) {
    v = oth.v, lv = oth.lv, rv = oth.rv;
  }
} pool[P], I = {0, 0, 0, -INF, -INF};

int n, q, a[MAXN], top, root[MAXN], R[MAXN];
vector<int> lsh;

Node comb(const Node &dat1, const Node &dat2) {
  Node res = I;
  res.v = dat1.v + dat2.v;
  res.lv = max(dat1.lv, dat1.v + dat2.lv);
  res.rv = max(dat2.rv, dat2.v + dat1.rv);
  return res;
}

void init(int &cur, int l, int r) {
  pool[cur = ++top].v++;
  if (l == r) {
    pool[cur].lv = pool[cur].rv = pool[cur].v;
    return;
  }
  int mid = l + r >> 1;
  init(pool[cur].ls, l, mid);
  init(pool[cur].rs, mid + 1, r);
  COMB(cur);
}

void add(int &cur, int ver, int l, int r, int pos) {
  pool[cur = ++top] = pool[ver], pool[cur].v -= 2;
  if (l == r) {
    pool[cur].lv = pool[cur].rv = pool[cur].v;
    return;
  }
  int mid = l + r >> 1;
  if (pos <= mid) add(pool[cur].ls, pool[ver].ls, l, mid, pos);
  else add(pool[cur].rs, pool[ver].rs, mid + 1, r, pos);
  COMB(cur);
}

Node query(int cur, int l, int r, int L, int R) {
  if (L > R) return I;
  if (L <= l && R >= r) return pool[cur];
  if (L > r || R < l) return I;
  int mid = l + r >> 1;
  return comb(query(pool[cur].ls, l, mid, L, R), query(pool[cur].rs, mid + 1, r, L, R));
}

int rnk(int x) {
  return lower_bound(lsh.begin(), lsh.end(), x) - lsh.begin() + 1;
}

bool check(int mid, int l1, int r1, int l2, int r2) {
  return query(root[R[mid]], 1, n, r1 + 1, l2 - 1).v + query(root[R[mid]], 1, n, l1, r1).rv + query(root[R[mid]], 1, n, l2, r2).lv >= 0;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  vector<pii> vec;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    lsh.push_back(a[i]);
    vec.push_back({a[i], i});
  }
  init(root[0], 1, n);
  sort(vec.begin(), vec.end());
  sort(lsh.begin(), lsh.end());
  lsh.erase(unique(lsh.begin(), lsh.end()), lsh.end());
  int w = lsh.size();
  for (auto &[x, id] : vec) x = rnk(x);
  for (int i = 1, j = 0; i <= w; i++) {
    for (; j < n && vec[j].first < i; j++) {
      add(root[j + 1], root[j], 1, n, vec[j].second);
    }
    R[i] = j;
  }
  cin >> q;
  for (int i = 1, a, b, c, d, last = 0; i <= q; i++) {
    cin >> a >> b >> c >> d;
    vector<int> qry = {(a + last) % n, (b + last) % n, (c + last) % n, (d + last) % n};
    sort(qry.begin(), qry.end());
    int l1 = qry[0] + 1, r1 = qry[1] + 1, l2 = qry[2] + 1, r2 = qry[3] + 1;
    int l = 1, r = w;
    while (l < r) {
      int mid = l + r + 1 >> 1;
      check(mid, l1, r1, l2, r2) ? l = mid : r = mid - 1;
    }
    cout << (last = lsh[l - 1]) << '\n';
  }
  return 0;
}