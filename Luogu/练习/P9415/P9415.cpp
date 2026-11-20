#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

const int MAXN = 5e5 + 10;
const ll INF = 4e18;

struct SegTree {
  ll dat[MAXN << 2];
  #define mid (l + r >> 1)
  #define LC root << 1, l, mid
  #define RC root << 1 | 1, mid + 1, r
  void build(int root, int l, int r) {
    if (l == r) {
      dat[root] = INF;
      return;
    }
    build(LC), build(RC);
    dat[root] = min(dat[root << 1], dat[root << 1 | 1]);
  }
  void update(int root, int l, int r, int pos, ll val) {
    if (l == r) {
      dat[root] = val;
      return;
    }
    if (pos <= mid) update(LC, pos, val);
    else update(RC, pos, val);
    dat[root] = min(dat[root << 1], dat[root << 1 | 1]);
  }
  ll query(int root, int l, int r, int L, int R) {
    if (L <= l && R >= r) return dat[root];
    ll ans = INF;
    if (L <= mid) ans = min(ans, query(LC, L, R));
    if (R > mid) ans = min(ans, query(RC, L, R));
    return ans;
  }
} T1, T2;

int n;
vector<int> vec[MAXN];
pii a[MAXN];
ll dp[MAXN];

void solve(int x) {
  int l = 1, r = x;
  while (l < r) {
    a[mid].first <= a[x].first + (dp[x] >> 1) ? r = mid : l = mid + 1;
  }
  vec[l - 1].push_back(x);
  T1.update(1, 1, n + 1, a[x].second, dp[x]);
}

bool cmp2(const pii &i, const pii &j) {
  return i.first == j.first ? i.second < j.second : i.first > j.first;
}

bool cmp1(const pii &i, const pii &j) {
  return i.second == j.second ? i.first > j.first : i.second < j.second;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    auto &[h, v] = a[i];
    cin >> h >> v;
  }
  sort(a + 1, a + n + 1, cmp1);
  for (int i = 1; i <= n; i++) a[i].second = i;
  sort(a + 1, a + n + 1, cmp2);
  a[n + 1].second = n + 1;
  T1.build(1, 1, n + 1), T2.build(1, 1, n + 1);
  fill(dp + 1, dp + n + 1, INF);
  solve(n + 1);
  for (int i = n; i >= 1; i--) {
    for (int v : vec[i]) {
      T1.update(1, 1, n + 1, a[v].second, INF);
      T2.update(1, 1, n + 1, a[v].second, (dp[v] + 1 >> 1) - a[v].first);
    }
    dp[i] = min(T1.query(1, 1, n + 1, a[i].second + 1, n + 1), T2.query(1, 1, n + 1, a[i].second + 1, n + 1) + a[i].first);
    solve(i);
  }
  ll ans = INF;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, dp[i]);
    if (a[i].first != a[i + 1].first) break;
  }
  cout << ans;
  return 0;
}