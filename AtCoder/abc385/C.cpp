#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 3e3 + 10;

int n, a[MAXN], mx, dp[MAXN][MAXN];
bool vis[MAXN];
vector<int> v[MAXN];

int C(int k) {
  fill(vis + 1, vis + n + 1, 0);
  for (int i = 0; i < v[k].size(); i++) {
    vis[v[k][i]] = 1;
  }
  int ans = 1;
  for (int i = 0; i < v[k].size(); i++) {
    for (int j = 1; j < v[k][i]; j++) {
      if (vis[v[k][i] - j]) {
        dp[v[k][i]][j] = dp[v[k][i] - j][j] + 1;
        ans = max(ans, dp[v[k][i]][j]);
      }
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  vector<int> w;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
    v[a[i]].push_back(i);
    w.push_back(a[i]);
  }
  sort(w.begin(), w.end());
  int l = unique(w.begin(), w.end()) - w.begin();
  int ans = 0;
  fill(&dp[0][0], &dp[n + 1][n + 1], 1);
  for (int i = 0; i < l; i++) {
    ans = max(ans, C(w[i]));
  }
  cout << ans;
  return 0;
}