#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e2 + 10;

struct Node {
  int u, v, step;
};

int n, dis[MAXN][MAXN];
char a[MAXN][MAXN], b[MAXN][MAXN];
queue<Node> q;

void R(int u, int v, int step) {
  if (dis[u][v] != -1) {
    return;
  }
  dis[u][v] = step;
  q.push({u, v, step});
}

void bfs() {
  fill(&dis[0][0], &dis[n][n] + 1, -1);
  for (int i = 1; i <= n; i++) {
    R(i, i, 0);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] != '-') {
        R(i, j, 1);
      }
    }
  }
  while (!q.empty()) {
    Node now = q.front();
    q.pop();
    for (int i = 1; i <= n; i++) {
      if (b[now.u][i] != '-') {
        for (int j = 1; j <= n; j++) {
          if (a[now.v][j] != '-' && b[now.u][i] == a[now.v][j]) {
            R(i, j, now.step + 2);
          }
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      b[j][i] = a[i][j];
    }
  }
  bfs();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << dis[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}