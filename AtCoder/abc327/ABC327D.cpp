#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;

int n, m, c[MAXN], a[MAXN], b[MAXN], flag;
bool vis[MAXN];
vector<int> g[MAXN];

void dfs(int x, int y) {
  if (vis[x]) {
    if (c[x] != y) {
      flag = 1;
    }
    return;
  }
  vis[x] = 1, c[x] = y;
  for (int i = 0; i < g[x].size(); i++) {
    dfs(g[x][i], !y);
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= m; i++) {
    g[a[i]].push_back(b[i]), g[b[i]].push_back(a[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i, 0);
    }
  }
  cout << (flag ? "No" : "Yes");
  return 0;
}