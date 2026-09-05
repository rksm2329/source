#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 5e3 + 10, INF = 2e18;

int n, ans, L[MAXN], R[MAXN];
vector<int> vec;

void dfs(int u, int cnt) {
  if (u == n + 1) {
    int edge = 0;
    for (int u : vec) {
      for (int v : vec) {
        if (u == v) continue;
        if (L[v] <= R[u] && R[v] >= R[u] || L[v] <= L[u] && R[v] >= L[u] || L[v] >= L[u] && R[v] <= R[u] || L[u] >= L[v] && R[u] <= R[v]) edge++;
      }
    }
    edge >>= 1;
    if (edge == cnt - 1) ans = max(ans, cnt);
    return;
  }
  dfs(u + 1, cnt);
  vec.push_back(u);
  dfs(u + 1, cnt + 1);
  vec.pop_back();
}

void Solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> L[i] >> R[i];
  }
  ans = 0;
  dfs(1, 0);
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  for (cin >> T; T--; Solve());
  return 0;
}