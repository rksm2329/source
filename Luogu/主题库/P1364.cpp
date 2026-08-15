#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110, INF = 1e9;

struct Tree {
  int left, right, father;
  int value;
} tree[MAXN];

int n, ans = INF;
bool vis[MAXN];

int S(int x, int d) {
  if (!x || vis[x]) {
    return 0;
  }
  vis[x] = 1;
  return S(tree[x].left, d + 1) + S(tree[x].right, d + 1) + S(tree[x].father, d + 1) + tree[x].value * d;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> tree[i].value >> tree[i].left >> tree[i].right;
  }
  for (int i = 1; i <= n; i++) {
    tree[tree[i].left].father = tree[tree[i].right].father = i;
  }
  for (int i = 1; i <= n; i++) {
    fill(vis + 1, vis + n + 1, 0);
    ans = min(ans, S(i, 0));
  }
  cout << ans;
  return 0;
}