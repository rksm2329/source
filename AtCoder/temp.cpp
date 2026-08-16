#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const int MAXN = 2e5 + 10;

struct Node {
  ll res;
  int ia, ib, ic;
  ll A, B, C;
  bool operator<(const Node &oth) const {
    return res > oth.res;
  }
};

int n, k;
ll a[3][MAXN];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 0; i < 3; i++) {
    for (int j = 1; j <= n; cin >> a[i][j++]);
    sort(a[i] + 1, a[i] + n + 1, greater<ll>());
  }
  multiset<Node> st;
  st.insert({a[0][1] * a[1][1] + a[1][1] * a[2][1] + a[0][1] * a[2][1], 1, 1, 1, a[0][1], a[1][1], a[2][1]});
  map<pair<pair<int, int>, int>, bool> mp;
  for (int i = 1; i < k; i++) {
    auto [res, ia, ib, ic, A, B, C] = *st.begin();
    st.erase(st.begin());
    if (ia < n && !mp.count({{ia + 1, ib}, ic})) {
      mp[{{ia + 1, ib}, ic}] = 1;
      st.insert({a[0][ia + 1] * (B + C) + B * C, ia + 1, ib, ic, a[0][ia + 1], B, C});
    }
    if (ib < n && !mp.count({{ia, ib + 1}, ic})) {
      mp[{{ia, ib + 1}, ic}] = 1;
      st.insert({a[1][ib + 1] * (A + C) + A * C, ia, ib + 1, ic, A, a[1][ib + 1], C});
    }
    if (ic < n && !mp.count({{ia, ib}, ic + 1})) {
      mp[{{ia, ib}, ic + 1}] = 1;
      st.insert({a[2][ic + 1] * (A + B) + A * B, ia, ib, ic + 1, A, B, a[2][ic + 1]});
    }
    while (st.size() > k) st.erase(prev(st.end()));
  }
  cout << (*st.begin()).res;
  return 0;
}