#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 5e4 + 10, INF = 1e9;

int n, m, dp[MAXN], ans[MAXN];
vector<pii> g[MAXN];

int check(vector<int> &son, int pos, int x) {
  int res = 0;
  for (int l = 0, r = son.size() - 1; r; r--, l++) {
    r -= r == pos;
    for (; l < r && son[l] + son[r] < x; l++);
    l += l == pos;
    if (l >= r) break;
    res++;
  }
  return res;
}

void dfs(int u, int fa, int x) {
  dp[u] = ans[u] = 0;
  vector<int> son;
  for (auto &[v, w] : g[u]) {
    if (v == fa) continue;
    dfs(v, u, x);
    dp[v] += w;
    if (dp[v] >= x) ans[u]++;
    else son.push_back(dp[v]);
  }
  sort(son.begin(), son.end());
  int k = son.size(), cnt = 0;
  for (int l = 0, r = k - 1; r; r--, l++) {
    for (; l < r && son[l] + son[r] < x; l++);
    if (l >= r) break;
    cnt++;
  }
  ans[u] += cnt;
  if ((cnt << 1) == k) return;
  int l = 0, r = k - 1;
  while (l < r) {
    int mid = l + r + 1 >> 1;
    check(son, mid, x) == cnt ? l = mid : r = mid - 1;
  }
  dp[u] = son[l];
}

bool check(int x) {
  dfs(1, 0, x);
  int res = 0;
  for (int i = 1; i <= n; res += ans[i++]);
  return res >= m;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1, u, v, w; i < n; i++) {
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  int l = 0, r = INF;
  while (l < r) {
    int mid = l + r + 1 >> 1;
    check(mid) ? l = mid : r = mid - 1;
  }
  cout << l;
  return 0;
}