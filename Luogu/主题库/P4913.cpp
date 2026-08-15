#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

struct Node {
  int l, r;
} a[MAXN];

int n;
int ans;

void dfs(int x, int depth) {
  if (!x) {
    ans = max(ans, depth);
    return;
  }
  dfs(a[x].l, depth + 1);
  dfs(a[x].r, depth + 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].l >> a[i].r;
  }
  dfs(1, 0);
  cout << ans;
  return 0;
}