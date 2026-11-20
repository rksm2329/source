#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pdi = pair<int, double>;

const int MAXN = 5e4 + 10;

struct SegTree {
  int n;
  pdi dat[MAXN << 2];
  vector<int> changed;
  
  pdi comb(const pdi &i, const pdi &j) {
    if (i.first == j.first) return {i.first, i.second + j.second};
    else if (i.first > j.first) return i;
    else return j;
  }
  
  void clear() {
    for (int node : changed) dat[node] = {0, 0.0};
    changed.clear();
  }
  
  void update(int root, int l, int r, int pos, int val, double cnt) {
    if (l == r) {
      if (changed.empty() || changed.back() != root) 
         changed.push_back(root);
      if (val == 0) {
        dat[root] = {0, 0.0};
      } else if (val > dat[root].first) {
        dat[root] = {val, cnt};
      } else if (val == dat[root].first) {
        dat[root].second += cnt;
      }
      return;
    }
    changed.push_back(root);
    int mid = (l + r) >> 1;
    if (pos <= mid) update(root << 1, l, mid, pos, val, cnt);
    else update(root << 1 | 1, mid + 1, r, pos, val, cnt);
    dat[root] = comb(dat[root << 1], dat[root << 1 | 1]);
  }
  
  pdi query(int root, int l, int r, int L, int R) {
    if (L <= l && R >= r) return dat[root];
    int mid = (l + r) >> 1;
    pdi res = {0, 0.0};
    if (L <= mid) res = comb(res, query(root << 1, l, mid, L, R));
    if (R > mid) res = comb(res, query(root << 1 | 1, mid + 1, r, L, R));
    return res;
  }
} T;

struct Node {
  int id, h, v;
  double ans1, ans2, cnt1, cnt2;
  bool operator<(const Node &oth) const {
    if (h != oth.h) return h > oth.h;
    return id < oth.id;
  }
} a[MAXN];

int n, m;

bool cmp_id(const Node &x, const Node &y) { return x.id < y.id; }

void cdq1(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  cdq1(l, mid);
  sort(a + l, a + mid + 1);
  sort(a + mid + 1, a + r + 1);
  T.clear();
  int cur = l;
  for (int i = mid + 1; i <= r; i++) {
    for (; cur <= mid && a[cur].h >= a[i].h; cur++) {
      T.update(1, 1, m, a[cur].v, (int)a[cur].ans1, a[cur].cnt1);
    }
    auto res = T.query(1, 1, m, a[i].v, m);
    if (res.first + 1 > a[i].ans1) {
      a[i].ans1 = res.first + 1;
      a[i].cnt1 = res.second;
    } else if (res.first + 1 == a[i].ans1) {
      a[i].cnt1 += res.second;
    }
  }
  sort(a + l, a + r + 1, cmp_id);
  cdq1(mid + 1, r);
  sort(a + l, a + r + 1, cmp_id);
}

void cdq2(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  cdq2(mid + 1, r);
  sort(a + l, a + mid + 1);
  sort(a + mid + 1, a + r + 1);
  T.clear();
  int cur = r;
  for (int i = mid; i >= l; i--) {
    for (; cur > mid && a[cur].h <= a[i].h; cur--) {
      T.update(1, 1, m, a[cur].v, (int)a[cur].ans2, a[cur].cnt2);
    }
    auto res = T.query(1, 1, m, 1, a[i].v);
    if (res.first + 1 > a[i].ans2) {
      a[i].ans2 = res.first + 1;
      a[i].cnt2 = res.second;
    } else if (res.first + 1 == a[i].ans2) {
      a[i].cnt2 += res.second;
    }
  }
  sort(a + l, a + r + 1, cmp_id);
  cdq2(l, mid);
  sort(a + l, a + r + 1, cmp_id);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  vector<int> lsh;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].h >> a[i].v;
    a[i].id = i;
    a[i].ans1 = a[i].ans2 = a[i].cnt1 = a[i].cnt2 = 1;
    lsh.push_back(a[i].v);
  }
  sort(lsh.begin(), lsh.end());
  lsh.erase(unique(lsh.begin(), lsh.end()), lsh.end());
  m = lsh.size();
  for (int i = 1; i <= n; i++) {
    a[i].v = lower_bound(lsh.begin(), lsh.end(), a[i].v) - lsh.begin() + 1;
  }
  sort(a + 1, a + n + 1, cmp_id);
  cdq1(1, n);
  sort(a + 1, a + n + 1, cmp_id);
  cdq2(1, n);
  sort(a + 1, a + n + 1, cmp_id);
  
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, a[i].ans1);
  }
  double cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i].ans1 == ans) cnt += a[i].cnt1;
  }
  cout << (int)ans << '\n';
  for (int i = 1; i <= n; i++) {
    if (a[i].ans1 + a[i].ans2 - 1 == ans) {
      cout << fixed << setprecision(6) << a[i].cnt1 * a[i].cnt2 / cnt;
    } else {
      cout << "0.000000 ";
    }
    if (i < n) cout << ' ';
  }
  return 0;
}