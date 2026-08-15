// ! O(2 ^ m)
#include <bits/stdc++.h>

using namespace std;

const int MAXM = 3e4 + 10;

int n, m, res, v[MAXM], p[MAXM];

// * 状态：当前为第 x 个物品，之前花了 sum 元，乘积为 ans，转移：(x,sum,ans) ->
// * (x + 1,sum,ans),(x + 1,sum + v[x],ans + v[x] * p[x])
void dfs(int x, int sum, int ans) {
  if (sum >= n) {
    return;
  }
  if (x == m + 1) {
    res = max(res, ans);
    return;
  }
  dfs(x + 1, sum, ans), dfs(x + 1, sum + v[x], ans + v[x] * p[x]);
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> v[i] >> p[i];
  }
  dfs(1, 0, 0);
  cout << res;
  return 0;
}