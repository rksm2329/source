#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;

int n, ans, dp[MAXN];
vector<int> g[MAXN];

void dfs(int u, int fa) {
  dp[u] = 1;
  vector<int> k;
  for (int v : g[u]) {
    if (v != fa) {
      dfs(v, u);
      k.push_back(dp[v]);
    }
  }
  sort(k.begin(), k.end(), greater<int>());
  if (k.size()) {
    ans = max(ans, k[0] + 1);
  }
  if (k.size() > 2) {
    dp[u] += k[0] + k[1] + k[2];
  }
  if (k.size() > 3) {
    ans = max(ans, k[0] + k[1] + k[2] + k[3] + 1);
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  cout << (ans < 5 ? -1 : ans);
  return 0;
}