#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 5e5 + 10;

int n, m, k, w[MAXN];
ll dp[MAXN];
vector<int> L[MAXN], R[MAXN];
pii a[MAXN];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    auto &[l, r] = a[i];
    cin >> l >> r >> w[i];
    if (r - l + 1 >= k) {
      L[l].push_back(w[i]);
      R[r].push_back(w[i]);
    }
  }
  multiset<int> st;
  for (int x : L[1]) st.insert(x);
  for (int i = k; i <= m; i++) {
    dp[i] = max(dp[i - 1], st.empty() ? 0 : dp[i - k] + *st.rbegin());
    for (int x : L[i - k + 2]) st.insert(x);
    for (int x : R[i]) st.erase(st.find(x));
  }
  cout << dp[m];
  return 0;
}