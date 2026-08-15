#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1e4 + 10;

int n, m;
int dis[MAXV];
queue<int> Q;

void record(int x, int cnt) {
  if (x < 0 || x > MAXV || dis[x] != -1) return;
  dis[x] = cnt;
  Q.push(x);
}

void bfs() {
  memset(dis, -1, sizeof(dis));
  for (record(n, 0); !Q.empty(); ) {
    int now = Q.front();
    Q.pop();
    if (now == m) {
      cout << dis[now];
      exit(0);
    }
    record(now - 1, dis[now] + 1);
    record(now * 2, dis[now] + 1);
  }
}

int main() {
  cin >> n >> m;
  bfs();
  return 0;
}