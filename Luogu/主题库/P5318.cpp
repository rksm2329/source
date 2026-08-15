#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

bool vis[MAXN];
vector<int> G[MAXN];
int n, m;
queue<int> q;

void dfs(int u) {
  vis[u] = 1;
  cout << u << ' ';
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (!vis[v]) {
      dfs(v);
    }
  }
}

void bfs() {
  q.push(1);
  vis[1] = 1;
  while (q.size()) {
    int u = q.front();
    q.pop();
    vis[u] = 1;
    cout << u << ' ';
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      if (!vis[v]) {
        vis[v] = 1;
        q.push(v);
      }
    }
  }
}

int main() {
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    sort(G[i].begin(), G[i].end());
  }
  dfs(1);
  cout << '\n';
  fill(vis + 1, vis + n + 1, 0);
  bfs();
  return 0;
}
