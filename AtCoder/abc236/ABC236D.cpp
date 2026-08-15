#include <bits/stdc++.h>

using namespace std;

long long n, a[20][20];
long long Ans;
int vis[20];

void Check() {
  long long ans = 0;
  for (int i = 1; i <= n * 2; i++) {
    for (int j = 1; j <= n * 2; j++) {
      if (i != j && vis[i] == vis[j]) {
        ans ^= a[i][j];
      }
    }
  }
  Ans = max(Ans, ans);
}

void dfs(int x, int k) {
  if (x == n * 2 + 1) {
    Check();
    return;
  }
  if (vis[x]) {
    dfs(x + 1, k);
  } else {
    for (int y = x + 1; y <= 2 * n; y++) {
      if (!vis[y]) {
        vis[x] = vis[y] = k;
        dfs(x + 1, k + 1);
        vis[x] = vis[y] = 0;
      }
    }
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= 2 * n - 1; i++) {
    for (int j = i + 1; j <= 2 * n; j++) {
      cin >> a[i][j];
    }
  }
  dfs(1, 1);
  cout << Ans;
  return 0;
}