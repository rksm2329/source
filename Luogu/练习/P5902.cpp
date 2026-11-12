#include <bits/stdc++.h>
// #define localtest

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 5e5 + 10, INF = 2e9;

struct SegTree {
  int dat[MAXN << 2];
  #define mid (l + r >> 1)
  #define lc root << 1
  #define rc root << 1 | 1
  #define LC lc, l, mid
  #define RC rc, mid + 1, r
  void build(int root, int l, int r) {
    if (l == r) {
      dat[root] = -INF;
      return;
    }
    build(LC), build(RC);
    dat[root] = max(dat[lc], dat[rc]);
  }
  void update(int root, int l, int r, int pos, ll val) {
    if (l == r) {
      dat[root] = val;
      return;
    }
    pos <= mid ? update(LC, pos, val) : update(RC, pos, val);
    dat[root] = max(dat[lc], dat[rc]);
  }
  int query(int root, int l, int r, int L, int R) {
    if (L <= l && R >= r) return dat[root];
    if (L > R || L > r || R < l) return -INF;
    return max(query(LC, L, R), query(RC, L, R));
  }
} T[2];

int n, u, d, s, dp[MAXN];
vector<pii> arr[MAXN];

int main() {
  #ifndef localtest
  freopen("salesman.in", "r", stdin);
  freopen("salesman.out", "w", stdout);
  #endif
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> u >> d >> s;
  int maxt = 0, L = s;
  for (int i = 1, t, l, m; i <= n; i++) {
    cin >> t >> l >> m;
    maxt = max(maxt, t), L = max(L, l);
    arr[t].push_back({l, m});
  }
  arr[++maxt].push_back({s, 0});
  T[0].build(1, 1, L), T[1].build(1, 1, L);
  T[0].update(1, 1, L, s, -s * u);
  T[1].update(1, 1, L, s, s * d);
  fill(dp + 1, dp + L + 1, -INF);
  for (int i = 1; i <= maxt; i++) {
    sort(arr[i].begin(), arr[i].end());
    for (auto &[l, m] : arr[i]) {
      int val1 = T[0].query(1, 1, L, l + 1, L) + l * u;
      int val2 = T[1].query(1, 1, L, 1, l - 1) - l * d;
      int now = max(val1, val2) + m;
      dp[l] = max(dp[l], now);
      T[0].update(1, 1, L, l, now - l * u);
      T[1].update(1, 1, L, l, now + l * d);
    }
    for (auto &[l, m] : arr[i]) {
      T[0].update(1, 1, L, l, -INF);
      T[1].update(1, 1, L, l, -INF);
    }
    sort(arr[i].begin(), arr[i].end(), greater<pii>());
    for (auto &[l, m] : arr[i]) {
      int val1 = T[0].query(1, 1, L, l + 1, L) + l * u;
      int val2 = T[1].query(1, 1, L, 1, l - 1) - l * d;
      int now = max(val1, val2) + m;
      dp[l] = max(dp[l], now);
      T[0].update(1, 1, L, l, now - l * u);
      T[1].update(1, 1, L, l, now + l * d);
    }
    for (auto &[l, m] : arr[i]) {
      T[0].update(1, 1, L, l, dp[l] - l * u);
      T[1].update(1, 1, L, l, dp[l] + l * d);
    }
  }
  cout << max(0, dp[s]);
  return 0;
}