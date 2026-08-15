#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;

int n, k, dp[MAXN];
vector<int> g[MAXN];

void dfs(int u, int fa) {
  for (int v : g[u]) {
    if (v != fa) {
      dfs(v, u);
    }
  }
  int cnt = 0, sum = 0;
  for (int v : g[u]) {
    if (v != fa) {
      cnt += dp[v] > 0, sum += dp[v];
    }
  }
  if (cnt >= 3 || (cnt == 2 && sum != k - 1)) {
    cout << "No";
    exit(0);
  }
  if (cnt == 2) {
    dp[u] = 0;
  } else if (!cnt) {
    dp[u] = k == 1 ? 0 : 1;
  } else {
    dp[u] = sum == k - 1 ? 0 : sum + 1;
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for (int i = 1, u, v; i < n * k; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  } 
  for (int i = 1; i <= n * k; i++) {
    if (g[i].size() == 1) {
      dfs(i, 0);
      break;
    }
  }
  cout << "Yes";
  return 0;
}