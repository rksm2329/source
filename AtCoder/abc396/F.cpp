#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;

struct Fenwick {
  ll n, dat[MAXN];
  void init(int n) {
    fill(dat + 1, dat + n + 1, 0);
    this->n = n;
  }
  int lowbit(int x) {
    return x & -x;
  }
  ll query(int pos) {
    ll ans = 0;
    for (; pos; ans += dat[pos], pos -= lowbit(pos));
    return ans;
  }
  void modify(int pos, ll val) {
    for (; pos <= n; dat[pos] += val, pos += lowbit(pos));
  }
} T;

int n, m, a[MAXN];
ll ans[MAXN];
pair<int, int> cnt[MAXN];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  T.init(m);
  for (int i = 1; i <= n; cnt[a[i]].first++, i++) {
    cin >> a[i];
    T.modify(a[i] + 1, 1);
    ans[0] += i - T.query(a[i] + 1);
  }
  for (int i = 1; i <= n; i++) {
    ans[m - a[i]] += i - 1 - cnt[a[i]].second++ - n + i + --cnt[a[i]].first;
  }
  for (int i = 0; i < m; i++) {
    cout << (ans[i] += ans[i - 1]) << '\n';
  }
  return 0;
}