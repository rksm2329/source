#include <bits/stdc++.h>

using namespace std;

int n, k, vis[15], a[15];

void dfs(int x, int m) {
  if (m == n) {
    for (int i = 1; i <= m; i++) {
      cout << a[i] << ' ';
    }
    cout << '\n';
    return;
  }
  vis[x]++;
  for (int i = 1; i <= k; i++) {
    if (vis[i] <= 1) {
      a[m + 1] = i;
      dfs(i, m + 1);
    }
  }
  vis[x]--;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  dfs(0, 0);
  return 0;
}