#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 10, MAXK = 1e2 + 10, INF = 2e6;

struct Node {
  int x, k;
};

int n, m, k, dis[MAXN][MAXK];
vector<int> a[MAXN], b[MAXN];

void init() {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      dis[i][j] = -1;
    }
  }
}

bool bfs(int mid) {
  init();
  queue<Node> Q;
  dis[n][0] = mid * k;
  for (Q.push({n, 0}); !Q.empty();) {
    int xx = Q.front().x, kk = Q.front().k;
    Q.pop();
    if (!dis[xx][kk])
      continue;
    for (int i = 0; i < a[xx].size(); i++) {
      if (b[xx][i] >= dis[xx][kk])
        continue;
      int y = a[xx][i], p = (kk + k - 1) % k;
      if (dis[y][p] != -1)
        continue;
      dis[y][p] = dis[xx][kk] - 1;
      Q.push({y, p});
    }
  }
  return dis[1][0] != -1;
}

void BinarySearch() {
  int l = 0, r = INF;
  while (l < r) {
    int mid = (l + r) >> 1;
    (bfs(mid) ? r = mid : l = mid + 1);
  }
  cout << (r == INF ? -1 : l * k);
}

int main() {
  cin >> n >> m >> k;
  for (int i = 1, u, v, w; i <= m; i++) {
    cin >> u >> v >> w;
    a[v].push_back(u);
    b[v].push_back(w);
  }
  BinarySearch();
  return 0;
}