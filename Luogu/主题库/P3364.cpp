#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10;

struct BIT {
  int n, dat[MAXN * 3];
  void init(int n) { this->n = n; }
  int get(int x) {
    int res = 0;
    for (; x; x -= x & -x) res = max(res, dat[x]);
    return res;
  }
  void add(int x, int v) {
    for (; x <= n; x += x & -x) dat[x] = max(dat[x], v);
  }
  void clear(int x) {
    for (; x <= n; x += x & -x) dat[x] = 0;
  }
} T;

struct Node {
  int lv, en, iq, at, ans;
  bool operator<(const Node &oth) const {
    return lv < oth.lv;
  }
} a[MAXN];

int n, m;

/*
l.at <= r.en
l.iq <= r.at
*/

bool cmp1(const Node &i, const Node &j) {
  return i.at < j.at;
}

bool cmp2(const Node &i, const Node &j) {
  return i.en < j.en;
}

void cdq(int l, int r) {
  if (l == r) return;
  int mid = l + r >> 1;
  cdq(l, mid);
  sort(a + l, a + mid + 1, cmp1);
  sort(a + mid + 1, a + r + 1, cmp2);
  int cur = l;
  for (int i = mid + 1; i <= r; i++) {
    for (; cur <= mid && a[cur].at <= a[i].en; cur++) {
      T.add(a[cur].iq, a[cur].ans);
    }
    a[i].ans = max(a[i].ans, T.get(a[i].at) + 1);
  }
  for (int i = l; i < cur; i++) T.clear(a[i].iq);
  sort(a + l, a + r + 1);
  cdq(mid + 1, r);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  vector<int> lsh;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].lv >> a[i].en >> a[i].iq >> a[i].at;
    a[i].ans = 1;
    lsh.push_back(a[i].iq);
    lsh.push_back(a[i].at);
    lsh.push_back(a[i].en);
  }
  sort(lsh.begin(), lsh.end());
  lsh.erase(unique(lsh.begin(), lsh.end()), lsh.end());
  int m = lsh.size();
  for (int i = 1; i <= n; i++) {
    a[i].iq = lower_bound(lsh.begin(), lsh.end(), a[i].iq) - lsh.begin() + 1;
    a[i].at = lower_bound(lsh.begin(), lsh.end(), a[i].at) - lsh.begin() + 1;
    a[i].en = lower_bound(lsh.begin(), lsh.end(), a[i].en) - lsh.begin() + 1;
  }
  sort(a + 1, a + n + 1);
  T.init(m);
  cdq(1, n);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, a[i].ans);
  }
  cout << ans;
  return 0;
}